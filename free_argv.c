#include "main.h"

/**
 * free_argv - function frees args and path
 * @args: double pointer
 *
 * Return: nothing
 */
void free_argv(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
