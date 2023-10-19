#include "monty.h"

/**
 * swap - Swaps the two elements of the stack at the top.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *up, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	up = *stack;
	second = up->next;

	up->next = second->next;
	second->prev = NULL;
	second->next = up;
	up->prev = second;

	*stack = second;
}
