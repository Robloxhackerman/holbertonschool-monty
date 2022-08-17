#include "monty.h"

/**
 * push_err - Prints error for push operation.
 * @line_number: Line of error.
 */

void push_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}


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
	int number;
	char *tok = NULL;

	if (head)
	{
		tok = strtok(NULL, " \n\r\t");
		if (!tok)
			push_err(line_number);

		if (check_number(tok) == 0)
			number = atoi(tok);
		else
			push_err(line_number);

		new = malloc(sizeof(stack_t));
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
