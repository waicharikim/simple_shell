#include "main.h"

int main(int ac __attribute__((unused)), char *av[]__attribute__((unused)))
{
  char *lineptr = NULL;
  char *prompt = "$ ";
  char **args;
  int status;

  if (isatty(STDIN_FILENO) == 1) /*checks if the shell is in interactive mode*/
  {
	  while (1) /* runs an infinite loop to display the prompt and take in arguments */
	  {
		  if(write(STDOUT_FILENO, prompt, 2) == -1)
			  exit(EXIT_FAILURE);

		lineptr =  get_line();
		args = tokenizer(lineptr);
		status = executor(args);
		free(lineptr);
	  }
  }

  /*free(lineptr);*/
	  return (0);
}
