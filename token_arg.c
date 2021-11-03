#include "shell.h"

/**
 *token_arg - tokenization of command line string
 *@_str: string created with input from command line
 *Return: arguments, pointer of a pointer
 */

char **token_arg(char *_str)
{
	int i = 0, numCom = 0;
	char **_args = NULL;
	char *_arg = NULL;
	char *str_sep = " \t\r\n\a";

	while (_str[numCom])
		numCom++;
	_args = malloc(numCom * (sizeof(char *)));
	if (!_args)
	{
		perror("Allocation unsucceded\n");
		exit(98);
	}
	_arg = strtok(_str, str_sep);
	while (_arg != NULL)
	{
		_args[i] = _arg;
		_arg = strtok(NULL, str_sep);
		i++;
	}
	_args[i] = NULL;
	return (_args);
}
