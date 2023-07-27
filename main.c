#include "main.h"
int main(int ac, char *av[], char **env);
/**
 * main - program entry point
 * @ac: argument count
 * @av: argument vector
 * @env: environment variable
 *
 * Return: 0 on success
 */

int main(int ac, char *av[], char **env)
{
	char *lineptr = NULL;
	char *prompt = "$ ";
	char **args;
	int i, status;
	char *alias, *cmd_path;

	(void)ac;
	(void)av;
	(void)env;

	if (isatty(STDIN_FILENO) == 1) /*checks if the shell is in interactive mode*/
	{
		/* runs an infinite loop to display the prompt and take in arguments */
		while (1)
		{
			if (write(STDOUT_FILENO, prompt, 2) == -1)
				exit(EXIT_FAILURE);

			lineptr =  get_line();
			args = tokenizer(lineptr);
			alias = isalias(args[0]);

			if (strcmp(args[0], "exit") == 0)
			{
				free(args);
				run_exit(args);
			}
			if (alias)
			{
				status = isbuiltin(alias, args);
				if (status == 0)
					continue;
			}
			status = isbuiltin(args[0], args);
			if (status == 0)
				continue;
			cmd_path = ispath(args[0]);

			if (cmd_path)
			{
				exec_utor(args);

			}
			else

				perror("Error: ");
			i = 0;
			while (args[i])
			{
				/* printf("%s\n", args[i]); */
				free(args[i]);
				i++;
			}
		/* status = executor(args); */
			free(lineptr);
			free(args);
		}
		return (-1);
	}
	return (0);
}
