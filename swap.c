#include "monty.h"

/**
 * swap - Swaps top two elements of stack.
 * @head: Adress of head pointer of stack.
 * @line_number: Line of monty file.
 */

void swap(stack_t **head, unsigned int line_number)
{
	int aux;

	if (head)
	{
		if (*head && (*head)->next)
		{
			aux = (*head)->n;
			(*head)->n = ((*head)->next)->n;
			((*head)->next)->n = aux;
		}
		else
		{
			free_stack(head);
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
			status = 1;
		}
	}
}
