#include "shell.h"

/**
 * _strcpy - Copies the string src to dest
 * @dest: Destiny pointer
 * @src: String source
 *
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *mem_address;

	mem_address = dest;

	while (*src != '\0')
	{
		*mem_address = *src;
		mem_address++;
		src++;
	}

	*mem_address = '\0';

	return (dest);
}
