#include "shell.h"

/**
 * rm_new_line - removes the new line with null character
 * @string: the argumments passed in the CL
 * Return: void
 */
void rm_new_line(char *string)
{
int i = 0;

while (string[i])
{
if (string[i] == '\n')
{
string[i] = '\0';
return;
}
i++;
}
}
