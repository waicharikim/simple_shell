#include "main.h"

/**
 * executor - searches and executes builtin commands
 * @tokens: list of tokens
 *
 * Return: 0 for success -1 for fail.
 */
int executor(char **tokens)
{
	int i;
	cmd builtin[5] = {
		{"cd", &run_cd},
		{"pwd", &run_pwd},
		{"ls", &run_ls},
		{"exit", &run_exit},
		{"help", &run_help}};

	for (i = 0; i < 5; i++)/*executes if input matches a builtin*/
	{
		if (builtin[i].cmd == *(tokens + 0))
			return (bultin[i].find_cmd(tokens));
	}
		return (process(tokens));
}
