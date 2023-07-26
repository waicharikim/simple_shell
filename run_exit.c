#include "main.h"

/**
 * run_exit - function allows specifying exit status
 * @strptr: array of pointers
 *
 * Return: 0 0n success
 */
int run_exit(char **strptr)
{
	int status = 0;

	if (strptr[1])
		status = atoi(strptr[1]);

	exit(status);
}
