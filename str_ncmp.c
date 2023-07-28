#include "main.h"

/**
 * str_ncmp - function compares the first num bytes of two strings
 * @s1: string one
 * @s2: string two
 * @num: compared bytes
 *
 * Return: 0 for identical bytes compared
 */
int str_ncmp(char *s1, char *s2, int num)
{
	int i = 0;

	if ((!s1) || (!s2) || (!num))
		return (-1);

	while (s1[i] && s2[i] && i < num)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
