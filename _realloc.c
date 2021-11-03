#include "shell.h"

/**
  * _realloc - function that reallocates a memory block
  * @ptr: block of memory to reallocatre
  * @old_size: size of memorry occupied by ptr
  * @new_size: size of the new memory to realloc
  * Return: a new reallocated string
  */

void *_realloc(void *ptr, int old_size, int new_size)
{
	char *s;
	int i = 0;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	s = malloc(new_size);
	if (s == NULL)
		return (NULL);
	if (ptr == NULL)
		return (s);
	while (i < new_size && i < old_size)
	{
		s[i] = ((char *) ptr)[i];
		i++;
	}
	free(ptr);
	return (s);
}
