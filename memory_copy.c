#include "shell.h"

/**
 * _memcpy - copy memory area
 * @dest: memory area dest
 * @src: memory area src
 * @n: copies n bytes
 *
 * Return: a pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
dest[i] = src[i];
return (dest);
}
