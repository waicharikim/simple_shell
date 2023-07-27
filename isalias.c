#include "main.h"

/**
 * isalias - checks if a command is an alias
 * @command: command to check for
 *
 * Return: real name of aliased command, NULL for no match
 */
char *isalias(char *command)
{
	int i = 0;
	alias alias_list[1] = {
		{"ls", "ls --color=auto"}};

	for (; i < 1; i++)
	{
		if (strcmp(command, alias_list[i].a_name) == 0)
			return (alias_list[i].cmd_name);
		return (NULL);
	}
	return (NULL);
}
