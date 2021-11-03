#include "shell.h"
/**
  *fun_cd - change the directory
  *@_args:arguments with the information of location
  *Return: Always 1
  */
int fun_cd(char **_args)
{
	printf("Entered fun_cd function: %s\n", _args[0]);
	return (1);
}

/**
  *fun_pwd - prints the current directory
  *@_args:arguments with the information of location
  *Return: Always 1
  */
int fun_pwd(char **_args)
{
	printf("Entered fun_pwd function: %s\n", _args[0]);
	return (1);
}

/**
  *fun_exit - exit the terminal
  *@_args:arguments with the information of location
  *Return: Always 0 or 1
  *
  */
int fun_exit(char **_args)
{
	char *ex = "exit";

	if (_strcmp(_args[0], ex) == 0)
	{

		return (0);
	}
	return (1);
}

/**
  *fun_envi - prints the enviromental variable
  *@env:enviromental valiable
  *Return: Always 1
  */
int fun_envi(char **env)
{
	int i = 0;

	while (env[i])
	{
		_printf("%s\n", env[i]);
		i++;
	}

	return (1);
}
