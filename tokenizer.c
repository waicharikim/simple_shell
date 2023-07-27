#include "main.h"

/**
 * tokenizer - function splits a string to tokens
 * @str: string to tokenize
 *
 * Return: pointer to an array
 */
char **tokenizer(char *str)
{
	int count = 0, i = 0;
	char *token, *str1;
	char **strptr;

	/* duplicate string for tokenizing */
	str1 = strdup(str);

	token = strtok(str, " \n");

	/* count the number of tokens passed for memory allocation */
	while (token)
	{
		token = strtok(NULL, " \n");
		count++;
	}
	/* printf("%d\n", count); */

	/* allocate memory for the counted number of tokens and a null pointer */
	strptr = malloc(sizeof(char *) * (count + 1));
	if (!strptr)
	{
		fprintf(stderr, "memory allocation failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(str1, " \n");

	while (token)
	{
		/* store the duplicate token at the ith index */
		strptr[i] = strdup(token);
		token = strtok(NULL, " \n");
		i++;
	}

	/* strptr is a null terminated array of strings */
	strptr[i] = NULL;
	free(str1);
	return (strptr);
}
