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
	int i;
	char *alias, *cmd_path;
	void ac;
	void(av);
	void(env);

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
			/* exec_utor(args); */

			if (alias)
			{
				isbuiltin(alias);
				continue;
			}
			if (isbultin(args[0]) == -1)
				cmd_path = ispath(args[0]);

			/* if (cmd_path)
			{
				execve();
			}
			else
				perror(); */

			i = 0;
			while (args[i])
			{
				/* printf("%s\n", args[i]); */
				exec_utor(args);
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
