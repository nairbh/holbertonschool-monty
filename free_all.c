#include "monty.h"

/**
 * free_stack - Frees a stack by deallocating the memory for each node.
 * @stack: Pointer to a pointer to the stack.
 *
 * This function frees the memory allocated to a stack
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	}
}
