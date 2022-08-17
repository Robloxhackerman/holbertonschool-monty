#include "monty.h"

/**
 * get_function - Takes line from monty and returns corresponding op function.
 * @buf: Pointer to buffer.
 * Return: Pointer to operator function.
 */

void (*get_function(char *buf))(stack_t **, unsigned int)
{
	instruction_t arr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop}
	};
	int i;

	if (buf)
	{
		for (i = 0; i < 7; i++)
		{
			if (strcmp(buf, arr[i].opcode) == 0)
				return (arr[i].f);
		}
	}
	return (NULL);
}
