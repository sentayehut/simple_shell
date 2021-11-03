#include "shell.h"
/**
 * built_in - compare argv passed with the builtins commands
 * @string: pointer with the line saved
 * @argv: the arguments passed
 * @env: environment variable
 * @ex_it: integer
 */
void built_in(char *string, char **argv, char **env, int *ex_it)
{
    if (_strcmp(argv[0], "exit") == 0)
    {
        free(argv);
        free(string);
        exit(*ex_it);
    }
    if (_strcmp(argv[0], "env") == 0)
        printenv(env, ex_it);
}
