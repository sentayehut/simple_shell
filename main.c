#include "shell.h"
/**
 *main - function to control the shell process
 *@ac:main argument, number of arguments
 *@av:main argument, array of arguments
 *@env:main argument, environmental variable
 *Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	char *_str = NULL, *no_command = "\n";
	char **_args = NULL;
	int _report = 1, kill_is = 0, cicles = 1;
	size_t _size_str;

	kill_is = isatty(STDIN_FILENO);
	if (kill_is)
		_printf("#cisfun$ ");
	while (_report && (getline(&_str, &_size_str, stdin) != EOF))
	{
		if (fun_count(_str) > 0)
		{
			if (_strcmp(_str, no_command) != 0)
			{
				_args = token_arg(_str);
				_report = exec_fun(&cicles, _args, av, env);
				free(_str);
				free(_args);
				_str = NULL;
				_args = NULL;

				if (kill_is && _report != 0)
					_printf("#cisfun$ ");
				cicles++;
			}
		}
		else if (kill_is != 0)
			_printf("#cisfun$ ");

	}

	if (kill_is && _report != 0)
		_printf("\n");
	free(_str);
	free(_args);
	ac = ac;
	return (0);
}
/**
  *fun_count - counts the letter in a string
  *@s:string to be evaluated
  *Return: number of letters
  */
int fun_count(char *s)
{
	int i = 0, cont = 0;

	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			cont++;
		i++;
	}
	return (cont);
}
