#include "main.h"

/**
 * str_cmp - function compares two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: 0, negative or positive value,
 * the string lengths dependent
 */
int str_cmp(char *str1, char *str2)
{
	int o = 0;

	while (str1[o] != '\0' && str2[o] != '\0')
	{
		if (str1[o] != str2[o])
			return (str1[o] - str2[o]);
		o++;
	}
	return (0);
}
