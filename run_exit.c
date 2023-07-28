#include "main.h"

/**
 * run_exit - function allows specifying exit status
 * @strptr: array of pointers
 *
 * Return: 0 0n success
 */
int run_exit(char **strptr)
{
	int status, len;

	if (strptr[1])
	{
		len = str_len(strptr[1]);
		status = atoi(strptr[1]);
		if (status == 0)
		{
			write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
			write(STDERR_FILENO, strptr[1], len);
			write(STDERR_FILENO, "\n", 1);
			free(strptr);
			return (0);
		}
		free(strptr);
		return (status);
	}
	return (-1);
}
