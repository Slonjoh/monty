#include "monty.h"

/**
 * add - Adds the two top elements of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int added_result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	added_result = (*stack)->n + ((*stack)->next)->n;
	pop(stack, line_number);
	(*stack)->n = added_result;
}
