#include "monty.h"

/**
 * push - Pushes an int into a stack.
 * @head: Pointer to first element of stack (last added).
 * @line_number: Line of monty command.
 *
 * Return: Pointer to new element or NULL if failed.
 */

void push(stack_t **head, unsigned int line_number)
{
	struct stack_s *new = NULL;
	extern int number;

	if (head)
	{
		new = malloc(sizeof(struct stack_s));
		if (!new)
			fprintf(stderr, "Error: malloc failed on line: %d\n", line_number);

		new->n = number;
		new->prev = NULL;
		new->next = NULL;

		if (*head == NULL)
			*head = new;
		else
		{
			(*head)->prev = new;
			new->next = *head;
			*head = new;
		}
	}
}
