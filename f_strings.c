#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: array
 * Return: length
 */
int _strlen(const char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);

	while (s[i])
		i++;
	return (i);
}

/**
 * _strdup - copy a strings with a malloc
 * @s1: array
 * Return: pointer to the copy
 */
char *_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * _strlen(s1) + 1);
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/**
 * _strncmp - compare if is equal 2 strings, first n chars
 * @s1: string1
 * @s2: string2
 * @n: n first characters
 * Return: 0 success; else pointer
 */
int	_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && s1 && s2 && s1[i] && s2[i] &&
			(unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/**
 * _strcmp - compare if is equal 2 strings
 * @s1: string1
 * @s2: string2
 * Return: 0 success; else pointer
 */
int     _strcmp(const char *s1, const char *s2)
{
		return (_strncmp(s1, s2, (size_t)-1));
}

/**
 * num_to_str - Convert a number to string format
 * @num: Number to be converted
 *
 * Return: Pointer to string representation of "num"
*/
char *num_to_str(int num)
{
	int num_rev = 0;
	int i, digits = 0;
	char *num_str = NULL;

	if (num == 0)
		digits = 1;
	else
		while (num > 0)
		{
			digits++;
			num_rev *= 10;
			num_rev += num % 10;
			num /= 10;
		}

	num_str = malloc(sizeof(char) * (digits + 1));
	if (num_str == NULL)
		dispatch_error("Error: Coudn't allocate memory for number conversion");

	for (i = 0; i < digits; i++)
	{
		num_str[i] = (num_rev % 10) + '0';
		num_rev /= 10;
	}
	num_str[i] = '\0';

	return (num_str);
}
