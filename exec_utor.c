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
	char *cmd = NULL;
	int status;
	pid_t child = fork();

	cmd = ispath(argv[0]);

	if (child == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else if (child > 0)
	{
		do {
			waitpid(child, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	       exit (EXIT_FAILURE);

	return (0);
}
