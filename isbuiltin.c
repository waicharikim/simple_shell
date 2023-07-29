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
	cmd builtin[3] = {
		/*{"cd", &run_cd},*/
		{"pwd", &run_pwd},
		{"help", &run_help}};

	for (i = 0; i < 4; i++)/*executes if input matches a builtin*/
	{
		if (str_cmp(builtin[i].cmd, tokens[0]) == 0)
		{
			status = builtin[i].find_cmd(tokens);
			if (status == 0)
				return (0);
			else
				return (-1);
		}
	}
	return (-1);
}
