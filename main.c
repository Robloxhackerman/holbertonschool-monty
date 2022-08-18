#include "monty.h"

int status = 0;

/**
 * main - Program that interprets monty files to build stacks.
 * @ac: Number of arguments passed to main.
 * @argv: Pointer to string arguments.
 *
 * Return: 0 on success, EXIT_FAILURE if fails.
 */

int main(int ac, char **argv)
{
	char *buf = NULL, *tok = NULL;
	size_t buf_size = 0;
	FILE *file = NULL;
	int line_number = 0;
	stack_t *stack = NULL;
	void (*f)(stack_t **, unsigned int) = NULL;

	file = open_file(ac, argv);
	while (getline(&buf, &buf_size, file) != -1)
	{
		line_number++;
		tok = strtok(buf, " \t\n\r");
		if (tok == NULL)
			continue;
		f = get_function(tok);
		if (f)
		{
			(*f)(&stack, line_number);
			if (status == 1)
				break;
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tok);
			status = 1;
			break;
		}
	}
	fclose(file);
	free(buf);
	free_stack(&stack);
	return (status);
}
