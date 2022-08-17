#include "monty.h"
#include <ctype.h>

/**
 * check_number - Function that checks a string for only digit chars.
 * @str: String to check.
 *
 * Return: 0 if all chars are digits or (+-), 1 otherwise.
 */

int check_number(char *str)
{
	while (str && *str)
	{
		if ((isdigit(*str) != 0) || (*str == '-' || *str == '+'))
			str++;
		else
			return (1);
	}
	return (0);
}