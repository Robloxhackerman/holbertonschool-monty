#include "monty.h"

/**
 * sub - Substracts top two elements of stack.
 * @head: Adress of head pointer of stack.
 * @line_number: Line of monty file.
 */

void sub(stack_t **head, unsigned int line_number)
{
	if (head)
	{
		if (*head && (*head)->next)
		{
			((*head)->next)->n -= (*head)->n;
			pop(head, line_number);
		}
		else
		{
			free_stack(head);
			fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
			status = 1;
		}
	}
}
