#include "monty.h"
/**
 * pall - Command to print all values on the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_count: Line num in the Monty byte code file
 */

void pall(stack_t **stack, unsigned int line_count)
{
	stack_t *current = *stack;
	(void)line_count;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
