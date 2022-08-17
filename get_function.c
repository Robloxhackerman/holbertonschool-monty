#include "main.h"

/**
 * get_function - Takes line from monty and returns corresponding op function.
 * @buf: Pointer to buffer.
 * @line: Line number.
 * Return: Pointer to operator function.
 */

void (*get_function(char *buf, unsigned int line))(stack_t **, unsigned int)
{
	char *operator = NULL, *number_str = NULL;
	instruction_t arr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint}
	};
	int i;
	extern int number;

	if (buf)
	{
		operator = strtok(buf, " \r\n\t");
		if (operator)
		{
			number_str = strtok(NULL, " \r\n\t");
			if (number_str)
				number = atoi(number_str);
			for (i = 0; i < 3; i++)
			{
				if (strcmp(operator, arr[i].opcode) == 0)
					return (arr[i].f);
			}
		}
	}
	fprintf(stderr, "L%d: unkown instruction %s\n", line, operator);
	return (NULL);
}
