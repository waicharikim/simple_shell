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
	int i, status, set = 0;
	char *cmd_path;
	(void)cmd_path;
	(void)ac;
	(void)av;

	/* runs an infinite loop to display the prompt and take in arguments */
	while (1)
	{
		/*checks if the shell is in interactive mode*/
		if (isatty(STDIN_FILENO) == 1)
		{
			if (write(STDOUT_FILENO, prompt, 2) == -1)
				exit(EXIT_FAILURE);
		}
		else
			set = 1;

		lineptr = get_line();
		if (!str_cmp(lineptr, "\n"))
		{
			free(lineptr);
			continue;
		}

		args = tokenizer(lineptr);

		/* alias = isalias(args[0]); */

		if (args == NULL || args[0] == NULL)
		{
			if (args[0] == NULL)
				free(args);

			free(lineptr);
			continue;
		}
		if (str_cmp(args[0], "exit") == 0)
		{
			status = run_exit(args, lineptr);
			if (status < 0)
				exit(2);
			else
				exit(status);
		}
		if (str_cmp(args[0], "env") == 0)
		{
			for (i = 0; env[i]; i++)
				;
			i--;
			for (; i >= 0; i--)
				printf("%s\n", env[i]);

			free(lineptr);
			free_argv(args);
			continue;
		}
		if (str_cmp(args[0], "cd") == 0)
		{
			if (args[1] == NULL)
			{
				chdir(getenv("HOME"));
				free_argv(args);
				free(lineptr);
				continue;
			}
			else
			{
				if (chdir(args[1]) != 0)
					fprintf(stderr, "%s: not found\n", args[1]);
				free_argv(args);
				free(lineptr);
				continue;
			}
			free_argv(args);
			free(lineptr);
			continue;
		}
/*
		status = isbuiltin(args);
		if (status == 0)
		{
			free(lineptr);
			free_argv(args);
			continue;
		}
		*/

		exec_utor(args, env, lineptr, set);

		i = 0;
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(lineptr);
		free(args);
	}
	return (0);
}
