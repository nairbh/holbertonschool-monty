#include "monty.h"

/**
 * _push - Pushes an integer onto the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The line number for error reporting.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int n = 0;
	char *arg = strtok(NULL, "\n\t\r ");

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = parse_arg(arg, line_number);

	add_node(stack, n);
}

/**
 * _pall - Prints all values in the stack from the top.
 * @stack: Pointer to a pointer to the stack.
 * @line_number: The line number (unused in this function).
 *
 * This function iterates through the stack and prints each value.
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;

	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
