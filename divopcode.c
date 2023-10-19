#include "monty.h"

/**
 * div_operator - Divides the 2nd top element by the 1st element of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void div_operator(stack_t **stack, unsigned int line_number)
{
	int first_top = (*stack)->n;
	int second_top = ((*stack)->next)->n;
	int div_result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (first_top == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	div_result = second_top / first_top;
	pop(stack, line_number);
	(*stack)->n = div_result;
}
