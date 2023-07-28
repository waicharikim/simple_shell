#include "main.h"

/**
 * str_cat - function concatenates strings
 * @s1: destination string
 * @s2: string to concatenate
 *
 * Return: pointer to concatenated string
 */
char *str_cat(char *s1, char *s2)
{
	unsigned int i = 0, s1_len;

	s1_len = str_len(s1);

	while (s2[i])
	{
		s1[s1_len + i] = s2[i];
		i++;
	}
	/* add null byte at the end of new string */
	s1[s1_len + i] = '\0';

	return (s1);
}
