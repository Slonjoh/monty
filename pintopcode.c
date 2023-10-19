#include "monty.h"

/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (current->next != NULL)
		current = current->next;

	printf("%d\n", (*stack)->n);
}
