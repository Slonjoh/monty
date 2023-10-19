#include "monty.h"

/**
 * pop - Delete top element from the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *up;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	up = *stack;
	*stack = up->next;

	if (up->next != NULL)
		up->next->prev = NULL;
	free(up);
}
