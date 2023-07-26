#include "main.h"
#include <sys/wait.h>
/**
 * exec_utor - function executes commands
 * @argv: an array of pointers
 * @cmd_path: pathname
 *
 * Return: 0 on success
 */
int exec_utor(char **argv)
{
	char *cmd = NULL;
	pid_t child = fork();
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
	else if (child == -1)
		return (-1);

	else
		wait(&status);

	return (0);
}
