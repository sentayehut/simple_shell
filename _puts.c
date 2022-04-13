#include "shell.h"

/**
 * _puts - Prints a string to stdout
 * @str: String to be printed
 *
 * Return: Number of chars printed
*/
int _puts(char *str)
{
	int len = _strlen(str);

	write(STDOUT_FILENO, str, len);

	return (len);
}
