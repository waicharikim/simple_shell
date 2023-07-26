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
	pid_t child = fork();
	int status;

	if (!child)
	{
		if (execve(argv[0], argv, NULL) == -1)
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
