#include "shell.h"

/**
  * func_env - this function will search for a PATH
  * @_com: the command to search in the PATH
  * @env: an array of arrays containing the path
  * @no_path: counts the number of elements inside PATH variable
  * Return: a string containing the path or NULL
  */
char *func_env(char *_com, char **env, int *no_path)
{
	int i = 0;
	char *_delim = "=:";
	char *_slash = "/";
	char *key = "PATH";
	char *concat_dir = NULL;
	char *concat_param = NULL;
	char *_temp = NULL;
	char *_token = NULL;

	while (env[i])
	{
		_temp = _strdup(env[i]);
		_token = strtok(_temp, _delim);
		if (_strcmp(_token, key) == 0)
		{
			while (_token)
			{
				*no_path = *no_path + 1;
				concat_dir = str_concat(_token, _slash);
				concat_param = str_concat(concat_dir, _com);
				if (access(concat_param, F_OK) == 0)
				{
					free(_temp);
					_temp = NULL;
					free(concat_dir);
					return (concat_param);
				}
				free(concat_dir);
				free(concat_param);
				_token = strtok(NULL, _delim);
				concat_param = NULL;
				concat_dir = NULL;
			}
		_token = NULL;
		}
		free(_temp);
		_temp = NULL;
		i++;
	}
	return (NULL);
}

/**
 *_strdup - creates a copy of a given array
 *@str: array to be copied
 *Return:a pointer to the array
 */
char *_strdup(char *str)
{
	int i;
	int j;
	char *t;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		i++;
	}
	i++;
	t = (char *) malloc(i * sizeof(char));
	if (t == NULL)
		return (NULL);
	for (j = 0; j < i; j++)
	{
		t[j] = str[j];
	}
	return (t);
}

/**
 *str_concat - Concatenate two strings
 *@s1: First string
 *@s2: Second string
 *Return:a pointer to the concatenated array
 */
char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0, k = 0, l = 0;
	char *t;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[i])
	{
		i++;
	}
	while (s2[j])
	{
		j++;
	}
	j++;
	t = (char *) malloc((i + j) * sizeof(char));
	if (t == NULL)
		return (NULL);
	for (k = 0; k < i; k++)
	{
		t[k] = s1[k];
	}
	for (l = 0; l < j; l++)
	{
		t[i + l] = s2[l];
	}
	return (t);
}
