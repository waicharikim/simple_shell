#include "main.h"

/**
 * isalias - checks if a command is an alias
 * @args: arguments
 *
 * Return: real name of aliased command, NULL for no match
 */
char *isalias(char **args)
{
	int status, i = 0;
	alias alias_list[1] = {
		{"ls", "ls --color=auto"}};

	for (; i < 1; i++)
	{
		if (strcmp(args[0], alias_list[i].alias_name) == 0)
		{
			status = isbuiltin(alias_list[i].cmd_name, args);
			if (status == -1)
			       	return (alias_list[i].cmd_name);
			return (NULL);
		}
		return (NULL);
	}
	return (NULL);
}
