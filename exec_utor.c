#include "main.h"
#include <sys/wait.h>
/**
 * exec_utor - function executes commands
 * @argv: an array of pointers
 *
 * Return: 0 on success
 */
int exec_utor(char *cmd_name, char **argv)
{
	char *cmd = NULL;
	int status;
	pid_t child = fork();

	cmd = ispath(cmd_name);
	printf("%s\n", cmd);
	if (!child)
	{
		if (execve(cmd, argv, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else if (child > 0)
		wait(&status);
	else
		return (-1);

	return (0);
}
