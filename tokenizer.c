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

	token = strtok(str, " \n");

	/* duplicate string for tokenizing */
	/* str1 = strdup(str); */

	/* count the number of tokens passed */
	while (token)
	{
		token = strtok(NULL, " \n");
		count++;
	}

	/* allocate memory for the counted number of tokens and a null pointer */
	strptr = malloc(sizeof(char *) * (count + 1));
	if (!strptr)
	{
		fprintf(stderr, "memory allocation failed");
		exit(EXIT_FAILURE);
	}

	str1 = stdup(str);
	token = strtok(str1, " \n");

	while (token)
	{
		/* store the duplicate token at the ith index */
		strptr[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	/* strptr is a null terminated string */
	strptr[i] = NULL;
	free(str1);
	return (strptr);
}
