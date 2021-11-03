#include "shell.h"

/**
 * _which - function that show the command which in shell
 * @source: doble pointer
 * @environ: list of vars
 * @test: path
 * @count_cmd: count of commands ls
 * Return: 1 in case of successful
 */
int _which(char **source, char **environ, dir **test, long int *count_cmd)
{
	int j = 0, i = 0, count_list = 0;
	struct stat st;
	dir *copia = *test;
	char **verificar;

	(void)environ;
	(void)count_cmd;
	for (count_list = 0; copia; copia = copia->next, count_list++)
	{
	}
	count_list++;
	if (source[1] == NULL)
		return (1);
	if (*source[1] != '/' && *source[1] != 46)
	{
		verificar = _verification(test, source[1], &count_list);
		for (j = 0; verificar[j]; j++)
		{
			if (stat(verificar[j], &st) != -1)
			{
				for (i = 0; *(verificar[j] + i); i++)
				{}
				write(1, verificar[j], i);
				write(1, "\n", 1);
				break;
			}
		}
		free_function(verificar, &count_list);
	}
	else
	{
		if ((stat(source[1], &st)) != -1)
		{
			for (i = 0; *(source[1] + i); i++)
			{}
			write(1, source[1], i);
			write(1, "\n", 1);
		}
	}
	return (1);
}
/**
 * _cd - function that show the command cd in shell
 * @source: doble pointer
 * @environ:list of vars ls
 * @test:path
 * @count_cmd:count of commands
 * Return: 1 in case of successful
 */
int _cd(char **source, char **environ, dir **test, long int *count_cmd)
{
	char s[100];
	char *msg = NULL;
	int sizenum = 0;

	(void)environ;
	(void)test;
	getcwd(s, 100);
	if (source[1] == NULL)
		return (1);
	if (chdir(source[1]) != 0)
	{
		msg = _union(count_cmd, &sizenum);
		perror(msg);
		free(msg);
	}
	return (1);
}
/**
 * _help - function that show the command help in shell
 * @source: doble pointer
 * @environ: this is the
 * @test:path
 * @count_cmd:count of commands
 * Return: 1 in case of successful
 */
int _help(char **source, char **environ, dir **test, long int *count_cmd)
{
	ssize_t fd, read_data = 0;
	char concatenar[6] = "help_";
	char *archivo = '\0';
	char buf[1024];
	int i = 0, j = 0, total = 0;

	(void)environ;
	(void)test;
	(void)count_cmd;
	if (source[1] == NULL)
		return (1);
	for (i = 0; *(source[1] + i); i++)
	{}
	i++;
	total = i + 5;
	archivo = malloc(sizeof(char) * (total));
	if (archivo == '\0')
		return (0);
	for (j = 0; concatenar[j]; j++)
		archivo[j] = concatenar[j];
	for (j = 0; *(source[1] + j); j++)
		archivo[5 + j] = *(source[1] + j);
	archivo[5 + j] = '\0';
	fd = open(archivo, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((read_data = read(fd, buf, 1024)) > 0)
	{
		write(STDOUT_FILENO, buf, read_data);
	}
	close(fd);
	free(archivo);
	return (1);
}
/**
 * _env - function that show the command env in shell
 * @source: doble pointer
 * @environ: this is the
 * @test:path
 * @count_cmd:count of commands
 * Return: 1 in case of successful
 */
int _env(char **source, char **environ, dir **test, long int *count_cmd)
{
	int i = 0, j = 0;
	char *env = NULL;
	(void)source;
	(void)test;
	(void)count_cmd;

	if (environ == NULL || *environ == NULL)
	{
		write(1, "not found enviromental variable\n", 32);
		return (1);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		env = environ[i];
		for (j = 0; env[j]; j++)
		{}
		write(STDOUT_FILENO, env, j);
		write(STDOUT_FILENO, "\n", 2);
	}
	return (1);
}
/**
 * _union - function that show the command union in shell
 * @sizenum: sizeof
 * @count_cmd:count of commands
 * Return: total
 */
char *_union(long int *count_cmd, int *sizenum)
{
	int i = 0;
	char *total = NULL;
	char *num = NULL;
	char inicio[5] = "sh: ";
	char inter[5] = ": cd";

	num = print_integers(count_cmd, sizenum);
	total = malloc(sizeof(char) * (9 + *sizenum));
	if (total == '\0')
		return ('\0');
	for (i = 0; inicio[i]; i++)
		total[i] = inicio[i];
	for (i = 0; i < *sizenum; i++)
		total[4 + i] = num[i];
	for (i = 0; inter[i]; i++)
		total[4 + *sizenum + i] = inter[i];
	total[4 + *sizenum + i] = '\0';
	free(num);
	return (total);
}
