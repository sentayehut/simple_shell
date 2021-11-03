#include "shell.h"

/**
 * _path - search for PATH in the env
 * @args: arguments saved on getline
 * @argv: arguments passed
 * @env: environment variable
 * @stad_exit: exit command
 * Return: 0 success
 */
int _path(char *args, char **argv, char **env, int *stad_exit)
{
	int i;
	char *tmp, *izq, *der;
	char *copy, *envcp;

	for (i = 0; env[i] != NULL; i++)
	{
		envcp = _strdup(env[i]);
		izq = strtok(envcp, "=\t");
		tmp = strtok(NULL, "=\t");
		if (_strcmp(izq, "PATH") == 0)
		{
			der = strtok(tmp, ":\t");
			while (der)
			{
				copy = print_path(der, args);
				if (access(copy, X_OK) == 0)
				{
					if (fork() == 0)
						execve(copy, argv, NULL);
					else
						wait(NULL);
					*stad_exit = 2;
					free(copy);
					free(envcp);
					return (0);
				}
				der = strtok(NULL, ":\t");
				free(copy);
			}
		}
		free(envcp);
	}
	return (2);
}

/**
 * print_path - makes a copy of path and print it
 * @der: saved tokens
 * @args: the arguments
 * Return: a char variable with the copy of path
 */
char *print_path(char *der, char *args)
{
	char *token, *copy;
	int tk_leng, leng;

	token = der;
	tk_leng = _strlen(token);
	leng = _strlen(args);
	copy = malloc((tk_leng + leng + 2) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	copy[0] = '\0';
	_strncat(copy, der);
	_strncat(copy, "/");
	_strncat(copy, args);
	_strncat(copy, "\0");
	return (copy);
}
