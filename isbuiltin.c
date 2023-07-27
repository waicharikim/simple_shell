#include "main.h"
/**
 * isbuiltin - searches and executes builtin commands
 * @tokens: list of tokens
 *
 * Return: 0 for success -1 for fail.
 */

int isbuiltin(char *cmd_name, char **tokens)
{
	int (*find_cmd)(char **);
	int i;
	int status;
	cmd builtin[4] = {
		{"cd", &run_cd},
		{"pwd", &run_pwd},
		{"exit", &run_exit},
		{"help", &run_help}};

	for (i = 0; i < 4; i++)/*executes if input matches a builtin*/
	{
		if (*(builtin[i].cmd) == *cmd_name)
		{
			find_cmd = builtin[i].find_cmd;
			status = find_cmd(tokens);
			if (status == 0)
			{
				free (tokens);
				return (0);
			}
		}
	}
	return (-1);
}
