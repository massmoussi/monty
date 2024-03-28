#include "monty.h"


/**
 * is_valid_integer - function to check if value is valid int
 *
 * @str: string to check
 *
 * Return: false or true
 */

bool is_valid_integer(const char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	if (*str == '\0')
	{
		return (false);
	}

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			return (false);
		}
		str++;
	}
	return (true);
}
