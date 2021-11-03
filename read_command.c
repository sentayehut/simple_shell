#include "shell.h"
/**
 * read_command - read a line from stdin
 * @env: the argument passed
 * Description: first we print the command prompt
 * then we read the command from standar input
 * Return: a pointer contaning the string passed to the CLI
 */
char *read_command(char **env)
{
char *string = NULL;
size_t bufsize = 0;
char **args = NULL;
ssize_t read = 0;
int i = 0, status, num_arg;
static int count, stad_exit;

if (signal(SIGINT, sighandler) == SIG_ERR)
perror("error:\n");
while (1 == 1)
{
if (isatty(STDIN_FILENO) == 1)
simple_print_shell("shell$ ");
read = getline(&string, &bufsize, stdin);
++count;
if (func_ctrl_d(string, read, &stad_exit) == 127)
continue;
rm_new_line(string);
args = _parser(string);
for (i = 0; args[i]; i++)
num_arg++;

built_in(string, args, env, &stad_exit);
status = _path(args[0], args, env, &stad_exit);
forkwaitexec(status, args, &count, &stad_exit);
{
fflush(stdin);
}
}
free(string);
return (0);
}
