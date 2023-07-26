#include "main.h"

/**
 * isbuiltin - searches and executes builtin commands
 * @tokens: list of tokens
 *
 * Return: 0 for success -1 for fail.
 */

int isbuiltin(char **tokens)
{
	int i;
	int status;
	cmd builtin[4] = {
		{"cd", &run_cd},
		{"pwd", &run_pwd},
		{"exit", &run_exit},
		{"help", &run_help}};

	for (i = 0; i < 4; i++)/*executes if input matches a builtin*/
	{
		if (builtin[i].cmd == *(tokens + 0))
		{
			status = builtin[i].find_cmd(tokens);
			if (status == 0)
				return (0);
		}
	}
		return (-1);
}