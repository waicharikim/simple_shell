#include "main.h"

/**
 * str_dup - function duplicates a string
 * @s: string to duplicate
 *
 * Return: pointer to string that is the duplicate
 */
char *str_dup(char *s)
{
	unsigned int i = 0, len;
	char *s_dup;

	if (s == NULL)
		return (NULL);

	len = str_len(s) + 1;

	s_dup = malloc(len * sizeof(char));

	if (s_dup == NULL)
		return (NULL);
	while (i < len)
	{
		s_dup[i] = s[i];
		i++;
	}
	return (s_dup);
}
