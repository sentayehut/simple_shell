#include "shell.h"

/**
 * write_history - Writes the history to a file in home dir
*/
void write_history(void)
{
	list_t *curr;
	int fd;
	char *home;

	home = _getenv("HOME");
	if (home == NULL)
		home = "/";

	if (chdir(home) == -1)
		return;

	fd = open(".simple_shell_history", O_CREAT | O_RDWR | O_APPEND, 0666);
	if (fd == -1)
		return;

	for (curr = *get_history_addrss(); curr != NULL; curr = curr->next)
	{
		write(fd, curr->str, curr->len);
		write(fd, "\n", 1);
	}

	close(fd);
}
