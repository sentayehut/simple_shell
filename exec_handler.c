#include"shell.h"

/**
 *exec_handler - creates a child process and schedule execution
 *@_args: arguments to use in the execution of the program
 *@av: parameter to indicate the name of the shell
 *@env:environ variable
 *@cicles: number of times parameters are passed
 *Return: Integer 1 or 0
 */

int exec_handler(int *cicles, char **_args, char **av, char **env)
{
	int status, childPID, _flag = 0, no_path;
	char *_str_ev = NULL;

	no_path = stat_fun(&_str_ev, &_flag, _args[0], *cicles, av[0], env);
	if (_str_ev != NULL)
	{
		_flag++;
		childPID = fork();
		if (childPID == 0)
			execve(_str_ev, _args, NULL);
		else if (childPID < 0)
			perror("command not ok");
		else if (childPID > 0)
		{
			do {
				waitpid(childPID, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	if (_flag == 0)
	{
		if (no_path != 1)
			_printf("%s: %d: %s: not found\n", av[0], *cicles, _args[0]);
	}
	if (_flag == 2)
		free(_str_ev);
	return (1);
}
