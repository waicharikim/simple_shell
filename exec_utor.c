#include "main.h"
#include <sys/wait.h>
/**
 * exec_utor - function executes commands
 * @argv: an array of pointers
 * @cmd_path: pathname
 *
 * Return: 0 on success
 */
int exec_utor(char **argv, char *cmd_path)
{
	pid_t child = fork();
	int status;

	if (!child)
	{
		if (execve(cmd_path, argv, NULL) == -1)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
	}
	else if (child == -1)
		return (-1);

	else
		wait(&status);

	return (0);
}
