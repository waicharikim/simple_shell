#include "main.h"
#include <sys/stat.h>

char *ispath(char *command, char **env);

/**
 * ispath - find the PATH to a command
 * @command: command to search PATH
 * @env: environment variable
 * Return: PATH to command
 */
char *ispath(char *command, char **env)
{
	int cmd_len, tok_len;
	char *envp, *token, *cmd_cpy, *cmd_path;
	struct stat buffer;

	if (command == NULL)
		return (NULL);

	envp = get_path(env);

	cmd_len = str_len(command);
	token = strtok(envp, "=:");
	while (token)
	{
		tok_len = str_len(token);
		cmd_path = malloc(tok_len + cmd_len + 2);
		if (!cmd_path)
		{
			exit(EXIT_FAILURE);
		}
		str_cpy(cmd_path, token);
		str_cat(cmd_path, "/");
		str_cat(cmd_path, command);


		if (stat(cmd_path, &buffer) == 0)
		{
			free(envp);
			return (cmd_path);
		}
		else
		{
			free(cmd_path);
			cmd_path = NULL;
			token = strtok(NULL, "=:");
		}
	}
	if (cmd_path == NULL)
	{
		cmd_cpy = str_dup(command);
		if (stat(command, &buffer) == 0)
		{
			free(envp);
			return (cmd_cpy);
		}
	}
	free(cmd_cpy);
	free(envp);
	return (NULL);
}
