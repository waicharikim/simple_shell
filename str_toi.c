#include "main.h"

/**
 * str_toi - function converts string to int
 * @str: string to convert
 *
 * Return: an integer
 */

int str_toi(char *str)
{
	int i = 0, num = 0, mul = 1;

	while (str[i + 1])
	{
		i++;
	}

	while (i >= 0)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (-1);
		}

		num += (str[i] - '0') * mul;
		mul *= 10;
		i--;
	}
	return (num);
}
