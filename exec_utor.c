#include "main.h"
#include <sys/wait.h>

int exec_utor(char **argv, char **env, char *lineptr, int set);
/**
 * exec_utor - function executes commands
 * @argv: an array of pointers
 * @env: environment variable
 * @set: an integer
 * @lineptr: line pointer
 *
 * Return: 0 on success
 */
int exec_utor(char **argv, char **env, char *lineptr, int set)
{
	pid_t child;
	char *cmd = NULL;
	int status;
	size_t len;

	cmd = ispath(argv[0], env);

	if (cmd == NULL)
	{
		len = str_len(argv[0]);
		write(STDERR_FILENO, "./hsh: 1: ", 10);
		write(STDERR_FILENO, argv[0], len);
		write(STDERR_FILENO, ": not found\n", 12);
		if (set == 0)
		{
			return (127);
		}
		else
		{
			free_argv(argv);
			exit(127);
		}
	}
	child = fork();
	if (!child)
	{
		if (execve(cmd, argv, env) == -1)
		{
			perror("Error");
			exit(2);
		}
	}
	else if (child > 0)
		waitpid(child, &status, 0);
	else
		return (-1);

	free(cmd);
	if (status == 512)
	{
		free_argv(argv);
		free(lineptr);
		exit(2);
	}
	return (2);
}
