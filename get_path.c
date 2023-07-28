#include "main.h"

/**
 * get_path - function gets path
 * @env: environment
 *
 * Return: a character pointer
 */
char *get_path(char **env)
{
	int i = 0;
	char *path_dup;

	while (env[i] != NULL)
	{
		if (str_ncmp("PATH", env[i], 4) == 0)
		{
			path_dup = str_dup(env[i]);
		}
		i++;
	}
	return (path_dup);
}

