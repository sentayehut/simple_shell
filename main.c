#include "shell.h"

static char *FIRST_ARG;

int handle_arguments(int ac, char **av, int *exec_file);
void sigintHandler(int sig_num);
char *get_first_av();

/**
 * main - Entry point
 * @ac: number of arguments
 * @av: Array of arguments
 *
 * Return: 0 on success
*/
int main(int ac, char **av)
{
	int read, exec_file = 0;
	char *buff = NULL;
	size_t buff_len = 0;
	int fd;

	FIRST_ARG = av[0];

	signal(SIGINT, sigintHandler);
	fd = handle_arguments(ac, av, &exec_file);
	/*update_count_lines();*/

	while (1)
	{
		/* Print console symbol only if it is interactive*/
		if (isatty(STDIN_FILENO) == 1 && exec_file == 0)
			write(STDOUT_FILENO, "$ ", 2);
		/* Read commands from console */
		/*read = read_line(fd, &buff);*/
		read = getline(&buff, &buff_len, stdin);
		if (read == EOF)
		{
			free(buff);
			exit(*process_exit_code());
		}
		/*handle_history(buff);*/
		/* Remove comments & '\n' char from buffer */
		buff = handle_comment(buff);
		_strtok(buff, "\n");
		/* Handling_semicolon, ||, && and executes inside of the function */
		handling_semicolon_and_operators(buff, read, av[0]);
	}
	/* Free buffer memory */
	free(buff);
	if (exec_file)
		close(fd);
	return (*process_exit_code());
}

/**
 * handle_arguments - Check the number of arguments passed to main
 * @ac: Number of arguments
 * @av: Array of arguments as strings
 * @exec_file: Integer used to check if user wants to exec commands from file
 *
 * Return: File descriptor to file
*/
int handle_arguments(int ac, char **av, int *exec_file)
{
	int fd = STDIN_FILENO;
	char *err_msg = "Error: more than one argument\n";

	if (ac > 2)
	{
		write(STDERR_FILENO, err_msg, _strlen(err_msg));
		exit(1);
	}
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		*exec_file = 1;
	}
	if (fd == -1)
	{
		perror(av[0]);
		exit(1);
	}

	return (fd);
}

/**
 * sigintHandler - Avoids current process to finish
 * @sig_num: Signal number
*/
void sigintHandler(int __attribute__((unused))sig_num)
{
	write(STDIN_FILENO, "\n$ ", 3);
}

/**
 * get_first_av - Returns the first argument passed to main
 *
 * Return: Pointer to first arg passed to main
*/
char *get_first_av(void)
{
	return (FIRST_ARG);
}
