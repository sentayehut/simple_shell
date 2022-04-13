#include "shell.h"

static int not_init_alias_head = 1;
static list_t *alias_head;

/**
 * get_alias_head - Returns alias_head pointer
 *
 * Return: Pointer to alias head var
*/
list_t **get_alias_head()
{
	if (not_init_alias_head == 1)
	{
		alias_head = NULL;
		not_init_alias_head = 0;
	}
	return (&alias_head);
}

/**
 * is_set_alias - Checks if the alias input is meant to set an alias
 * @alias_pair: String as alias arg input
 *
 * Return: 1 for true, 0 otherwise
*/
int is_set_alias(char *alias_pair)
{
	int i;

	/* Check for the '=' sign */
	/* the '=' sign shouldn't at indx 0 */
	for (i = 1; alias_pair[i] != '\0'; i++)
		if (alias_pair[i] == '=')
			return (1);

	return (0);
}

/**
 * set_alias - adds or updates aliases
 * @alias_pair: String in the form name=value
*/
void set_alias(char *alias_pair)
{
	char tmp_buff[250];
	int first_eq, last_eq;
	list_t *curr;
	list_t **alias_addrs = get_alias_head();

	/* Find first '=' sign */
	for (first_eq = 1; alias_pair[first_eq] != '\0'; first_eq++)
		if (alias_pair[first_eq] == '=')
			break;

	/* Copy the text before '=' */
	strncpy(tmp_buff, alias_pair, first_eq);
	tmp_buff[first_eq] = '\0';
	/* Append = and ' symbols */
	_strcat(tmp_buff, "='");

	/* Find last eq in case of putting '=' secuentially */
	for (last_eq = first_eq; alias_pair[last_eq] != '\0'; last_eq++)
		if (alias_pair[last_eq] != '=')
			break;

	/* Copy the second part of the alias */
	_strcat(tmp_buff, &alias_pair[last_eq]);
	_strcat(tmp_buff, "'");

	/* Add alias to the global list */
	for (curr = *alias_addrs; curr != NULL; curr = curr->next)
		if (_strncmp(curr->str, alias_pair, first_eq) == 0 &&
				(curr->str)[first_eq] == '=')
		{ /* Update already existing alias */
			free(curr->str);
			curr->str = _strdup(tmp_buff);
			return;
		}

	/* Add new alias to the list */
	add_node_end(alias_addrs, tmp_buff);
}

/**
 * handle_alias_args - Evaluates alias input command and decides what to do
 * @commands: Arrays of commands
 * @out_addrs: Pointer to out's head node
 *
 * Return: -1 if error happens, 0 otherwise
*/
int handle_alias_args(char **commands, list_t **out_addrs)
{
	int i, len, was_alias;
	int status = 0;
	list_t *curr;
	list_t **alias_addrs = get_alias_head();

	set_process_exit_code(0);
	for (i = 1; commands[i] != NULL; i++)
	{
		was_alias = 0;
		len = _strlen(commands[i]);
		/* Check that if user is trying to print an alias */
		for (curr = *alias_addrs; curr != NULL; curr = curr->next)
		{
			if (_strncmp(curr->str, commands[i], len) == 0 && (curr->str)[len] == '=')
			{ /* Means to list an alias */
				was_alias = 1;
				add_node_end(out_addrs, curr->str);
				break;
			}
		}
		if (was_alias)
			continue;
		/* Here, user is trying to set an alias or print an unexistent one */
		if (is_set_alias(commands[i]))
			set_alias(commands[i]); /* Validate that the set format is fine */
		else /* Print errors */
		{
			status = -1;
			set_process_exit_code(1);
			_puts("alias: ");
			_puts(commands[i]);
			_puts(" not found\n");
		}
	}

	return (status);
}

/**
 * handle_aliases - Handle alias replacement
 * @commands: Arrays of commands
*/
void handle_aliases(char **commands)
{
	list_t *curr;
	list_t **alias_addrs = get_alias_head();
	int cmd_len = _strlen(commands[0]);
	char *str;
	char tmp_buff[250];
	int i, alias_len = 0;

	if (commands[0] == NULL)
		return;

	/* Initialize buffer */
	for (i = 0; i < 250; i++)
		tmp_buff[i] = '\0';

	/* Search if a command is an alias */
	for (curr = *alias_addrs; curr != NULL; curr = curr->next)
	{
		str = curr->str;
		if (_strncmp(commands[0], str, cmd_len) == 0 && str[cmd_len] == '=')
		{ /* the command is an alias */
			alias_len = _strlen(&str[cmd_len + 2]); /* +2 beacause of "='" chars */
			strncpy(tmp_buff, &str[cmd_len + 2], alias_len - 1);
			tmp_buff[alias_len] = '\0';
			/* Free and then update the command */
			free(commands[0]);
			commands[0] = duplicate_string(tmp_buff);
			break;
		}
	}
}
