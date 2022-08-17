#include "monty.h"

/**
 * pall - Prints stack.
 * @head: Pointer to first element (last added).
 * @line_number: Line number.
 *
 * Return: Number of elements in stack.
 */

void pall(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *cursor = NULL;

	if (head)
		cursor = *head;

	while (cursor)
	{
		printf("%d\n", cursor->n);
		cursor = cursor->next;
	}
}
