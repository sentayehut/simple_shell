#include <unistd.h>

/**
* _putchar - writes the character c to stdout
* @c: The character to print
* @p: pointer to update the length
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c, int *p)
{
	*p += 1;

	return (write(1, &c, 1));
}
