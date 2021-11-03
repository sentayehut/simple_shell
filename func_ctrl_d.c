#include "shell.h"
/**
 * func_ctrl_d - allows use of ctrl d as way of shutting down shell
 * @string: the argument passed
 * @read: size of the saved string
 * @stad_exit: integer static var
 * Return: 0 success, otherwise 1
 */
int func_ctrl_d(char *string, ssize_t read, int *stad_exit)
{
	int i = 0;

	if (read == EOF && isatty(STDIN_FILENO) == 0)
	{
		free(string);
		exit(*stad_exit);
	}
	if (read == EOF && isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(string);
		exit(*stad_exit);
	}
	if (_strcmp(string, "\n") == 0)
	{
		*stad_exit = 0;
		return (127);
	}
	while (string[i] != '\n')
	{
		if (string[i] != ' ' && string[i] != '\t')
			return (0);
		++i;
	}
	*stad_exit = 0;
	return (127);
}
