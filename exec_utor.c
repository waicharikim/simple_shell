#include "main.h"
#include <sys/wait.h>
/**
 * exec_utor - function executes commands
 * @argv: an array of pointers
 *
 * Return: 0 on success
 */
int exec_utor(char **argv)
{
	pid_t child = fork();
	char *cmd = NULL;
	int status;

	cmd = ispath(argv[0]);

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
