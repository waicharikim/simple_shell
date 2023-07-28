#include "main.h"

/**
 * str_cpy - function copies a string
 * @str1: string to copy to
 * @str2: string to copy from
 *
 * Return: copied string
 */
char *str_cpy(char *str1, char *str2)
{
	int i = 0, t = 0;

	while (*(str2 + t) != '\0')
		t++;
	while (i < t)
	{
		str1[i] = str2[i];
		i++;
	}
	str1[t] = '\0';
	return (str1);
}
