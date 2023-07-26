#include "main.h"

/**
 * run_cd - changes working directory
 * args: target directory
 *
 * Return: 0 for Success -1 for failure
 */
int run_cd(char **args)
{
	char *env;

	if (args[1] == NULL)
	{
		env = getenv("HOME");
		chdir(env);
		return (0);
	}
	else
	{
		if (chdir(args[1]) != 0)
		    fprintf(stderr, "%s: not found\n", args[1]);
		return (-1);
	}
	return (0);
}
