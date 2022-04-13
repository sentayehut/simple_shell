#include "shell.h"

static int EXIT_CODE;
static int no_init_exit_code = 1;

/**
 * process_exit_code - Returns the address at which EXIT_CODE is stored
 *
 * Return: Address of EXIT_CODE var
*/
int *process_exit_code()
{
	if (no_init_exit_code)
	{
		EXIT_CODE = 0;
		no_init_exit_code = 0;
	}

	return (&EXIT_CODE);
}

/**
 * set_process_exit_code - Sets the value for EXIT_CODE var
 * @code: Number representing exit code
*/
void set_process_exit_code(int code)
{
	EXIT_CODE = code;
}
