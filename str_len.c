#include "main.h"

/**
 * str_len - function returns string length
 * @str: a string
 *
 * Return: string length
 */
int str_len(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}
