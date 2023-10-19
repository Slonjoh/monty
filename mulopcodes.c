#include "monty.h"

/**
 * mul_operator - Multiplies the two top elements of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void mul_operator(stack_t **stack, unsigned int line_number)
{
	int first_top = (*stack)->n;
	int second_top = ((*stack)->next)->n;
	int mul_result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	mul_result = second_top * first_top;
	pop(stack, line_number);
	(*stack)->n = mul_result;
}
