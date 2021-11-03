#include "shell.h"
/**
 * _strlen - function return length of string
 * @s: string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
int i = 0;

while (s[i] != '\0')
i++;
return (i);
}

/**
 * _strcpy - copy string from source to destination including
 * terminating null byte
 * @dest: destination for string to be copied
 * @src: string to be copied
 *
 * Return: pointer to destinationng
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

while (i <= _strlen(src))
{
dest[i] = src[i];
i++;
}
return (dest);
}

/**
 * _strncat - concatenates two strings
 * @dest: character string destination
 * @src: character string source
 *
 * Return: pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src)
{
int leng = _strlen(dest);
int i;

for (i = 0; src[i] != '\0'; i++)
dest[leng + i] = src[i];
dest[leng + i] = '\0';
return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: character string 1
 * @s2: character string 2
 *
 * Return: an integer less than, equal to, or greater than zero if s1
 * found, respectively, to be less then, to march, or be greater than s2
 */
int _strcmp(char *s1, char *s2)
{
int i = 0;

while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] != s2[i])
return ((int) s1[i] - s2[i]);
i++;
}
return (0);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: character
 *
 * Return: a pointer to a new string which is a duplicate of the string
 */
char *_strdup(char *str)
{
int i, j = 0;
char *ptr;

if (str == NULL)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
j++;
ptr = malloc(sizeof(char) * j + 1);
if (ptr == NULL)
return (NULL);
for (i = 0; i < j; i++)
ptr[i] = str[i];
ptr[j] = '\0';
return (ptr);
}
