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

/**
 * division - Divides second top elements of stack by the top element.
 * @head: Adress of head pointer of stack.
 * @line_number: Line of monty file.
 */

void division(stack_t **head, unsigned int line_number)
{
	if (head)
	{
		if (*head && (*head)->n)
		{
			if ((*head)->n == 0)
			{
				fprintf(stderr, "L%d: division by zero\n", line_number);
				status = 1;
				return;
			}
			((*head)->next)->n /= (*head)->n;
			pop(head, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
			status = 1;
		}
	}
}
