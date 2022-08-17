#include "monty.h"

/**
 * main - Program that interprets monty files to build stacks.
 *
 * Return: 0 on success, EXIT_FAILURE if fails.
 */

int main(int ac, char **argv)
{
	char *buf = NULL, *tok = NULL;
	size_t buf_size = 0;
	FILE *file = NULL;
	stack_t *stack = NULL;
	int line_number = 1;
	void (*f)(stack_t **, unsigned int) = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (getline(&buf, &buf_size, file) != -1)
	{
		tok = strtok(buf, " \t\n\r");
		if (tok == NULL)
			continue;
		f = get_function(tok);
		if (f)
			(*f)(&stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tok);
			return (EXIT_FAILURE);
		}
		line_number++;
	}

	fclose(file);
	free(buf);
	return (0);
}
