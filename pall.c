#include "main.h"

/**
 * pall - Prints stack.
 * @head: Pointer to first element (last added).
 *
 * Return: Number of elements in stack.
 */

int pall(struct stack_s *head)
{
	int count = 0;

	while (head)
	{
		printf("%d\n", head->n, count++);
		head = head->next;
	}

	return (count);
}
