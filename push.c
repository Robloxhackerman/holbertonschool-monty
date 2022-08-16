#include "main.h"

/**
 * push - Pushes an int into a stack.
 * @head: Pointer to first element of stack (last added).
 * @n: Int to add.
 *
 * Return: Pointer to new element or NULL if failed.
 */

struct stack_s *push(struct stack_s *head, int n)
{
	struct stack_s *new = NULL;

	new = malloc(sizeof(struct stack_s));
	if (!new)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (!head)
		return (new);	
	else
	{
		*head->prev = new;
		new->next = head;
		head = new;
	}

	return (head);
}
