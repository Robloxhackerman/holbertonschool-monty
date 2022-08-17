#include "monty.h"

/**
 * pint - Function that frees a stack of ints.
 * @head: Adress of head pointer.
 * @line_number: Line number.
 */

void pint(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	if (head && *head)
		printf("%d\n", (*head)->n);
	else if
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
}
