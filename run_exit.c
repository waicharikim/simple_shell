#include "main.h"

/**
 * run_exit - function allows specifying exit status
 * @strptr: array of pointers
 *
 * Return: 0 0n success
 */
int run_exit(char **strptr)
{
	int status;

	if (strptr[1] != NULL)
		status = atoi(strptr[1]);
	free(strptr);
	exit(status);
}
