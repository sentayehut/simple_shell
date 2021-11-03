#include "shell.h"
/**
 * forkwaitexec - executes the commands passed
 * @args: commands passed in CL
 * @status: receiving the status true or false
 * @count: variable that counts the commands passed
 * @stad_exit: integer static
 * Return: void
 */
void forkwaitexec(int status, char **args, int *count, int *stad_exit)
{
	if (status == 2)
	{
		if (access(args[0], F_OK) == 0)
		{
			if (fork() == 0)
				execve(args[0], args, NULL);
			else
				wait(NULL);
			*stad_exit = 0;
		}
		if (access(args[0], F_OK) != 0)
		{
			print_string("sh: ");
			print_count(count);
			print_string(": ");
			perror(args[0]);
			*stad_exit = 127;
		}

		if (access(args[0], F_OK) == 0 && access(args[0], X_OK) != 0)
		{
			print_string("sh: ");
			print_count(count);
			print_string(": ");
			perror(args[0]);
			*stad_exit = 126;
		}
		if (access(args[0], F_OK | R_OK | X_OK) == -1)
		free(args), args = NULL;
	}
	free(args);
}
/**
 * print_count - count and prints the number of commands passed
 * @count: int with the counter of commands passed
 * Return: void
 */
void print_count(int *count)
{
	int i, n, cnt = 0, len = 0;
	unsigned int base = 1, max, a;

	n = *count;
	max = n;
	a = max;
	do {
		a /= 10;
		++len;
	} while (a != 0);
	cnt += len;
	for (i = 0; i < len - 1; i++)
		base *= 10;
	_putchar('0' + (max / base));
	if (len > 1)
	{
		for (i = 0; i < len - 2; i++)
		{
			base /= 10;
			a = max / base;
			_putchar('0' + a % 10);
		}
		_putchar('0' + (max % 10));
	}
}
/**
 * _putchar - our own putchar function
 * @c: the char passed to the function
 * Return: 0 success otherwise 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
