#include "shell.h"

/**
 * f_strjoin - concatenates string 1 + string 2
 * @s1: string 1
 * @s2: string 2
 * Return: copy of string with null terminated char
 */
char *f_strjoin(char const *s1, char const *s2)
{
	size_t	l3;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	l3 = _strlen(s1) + _strlen(s2);
	s3 = malloc(l3 + 1);
	if (s3 == NULL)
		return (NULL);
	s3[0] = '\0';
	_strcat(s3, s1);
	_strcat(s3, s2);
	s3[l3] = '\0';
	return (s3);
}

/**
 * f_strsub - function that substract a paragraph from string
 * @s: string
 * @start: index of start
 * @len: len of characters to do a copy
 * Return: copy of string with null terminated char
 */
char *f_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*us;

	us = (char *)malloc(len + 1);
	if (s == NULL || us == NULL)
		return (NULL);
	i = 0;
	while (len-- && s[start + i])
	{
		us[i] = s[start + i];
		i++;
	}
	us[i] = '\0';
	return (us);
}

/**
 * f_memdel - function that free an array
 * @ap: array of strings
 * Return: void
 */
void f_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

/**
 * f_strdel - function that delete an array of strings
 * @as: array of strings
 * Return: void
 */
void f_strdel(char **as)
{
	f_memdel((void **)as);
}
