#include "main.h"
/**
 * get_line - reads a line from the terminal
 *
 * Return: 0 for success -1 for failure
 */
char *get_line(void)
{
	ssize_t gLine;
	char *lineptr = NULL;
	size_t buf = 0;

	gLine = getline(&lineptr, &buf, stdin);
	if (gLine == -1)/* checks if getline fails == exiting the shell*/
	{
		if (feof(stdin))
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(lineptr);
			fprintf(stderr, "Error: Failed to read from stdin");
			exit(EXIT_FAILURE);
		}
	}
	printf("The value of buffer is: %li\n", gLine);
	printf("The size of buffer is: %li\n", buf);
	printf("%s", lineptr);
	return (lineptr);
}