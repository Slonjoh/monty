#include "monty.h"

/**
 * push - Pushes element onto the stack
 * @line_count: Line num in the Monty byte code file
 */

void push(unsigned int line_count, stack_t **stack)
{
	char *arg = strtok(NULL, " \t\n");
	int a;
	int i;

	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_count);
		exit(EXIT_FAILURE);
	}

	for (i = 0; arg[i] != '\0'; i++)
	{
		if ((arg[i] != '-' && i == 0) || (!isdigit(arg[i]) && arg[i] != '-'))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_count);
			exit(EXIT_FAILURE);
		}
	}
	a = atoi(arg);
	push_to_stack(stack, a);
}
/**
 * push_to_stack - Pushes an integer onto the stack.
 * @stack: A double pointer to the beginning of the stack.
 * @value: The integer value to be pushed onto the stack.
 */

void push_to_stack(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed in push_to_stack\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
