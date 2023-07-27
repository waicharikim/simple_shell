#include "main.h"
#include <sys/stat.h>

char *ispath(char *command);

/**
 * ispath - find the PATH to a command
 * @command: command to search PATH
 *
 * Return: PATH to command
 */
char *ispath(char *command)
{
	int count, cmd_len, i, tok_len;
	char *env, *envp, *token, *cmd_path;
	char **tokens;
	struct stat buffer;

	count = 0;
	env = getenv("PATH");
	envp = strdup(env); /* duplicate PATH value*/
	token = strtok(env, ":");
	while (token) /* count the number of tokens*/
	{
		token = strtok(NULL, ":");
		count++;
	}

	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
	{
		fprintf(stderr, "memory allocation failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(envp, ":");
	while (token)
	{
		tokens[i] = strdup(token);
		token =	strtok(NULL, ":");
		i++;
	}
	tokens[i] = NULL;
	free(envp);

	cmd_len = strlen(command);

	/* i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	} */
	i = 0;
	while (tokens[i])
	{
		tok_len = strlen(tokens[i]);
		cmd_path = malloc(tok_len + cmd_len + 2);
		if (!cmd_path)
		{
			fprintf(stderr, "memory allocation failed");
			exit(EXIT_FAILURE);
		}
		strcpy(cmd_path, tokens[i]);
		strcat(cmd_path, "/");
		strcat(cmd_path, command);
		strcat(cmd_path, "\0");

		if (stat(cmd_path, &buffer) == 0)
		{
			return (cmd_path);
		}
		else
			free(cmd_path);
		i++;
	}
	return (NULL);
}
