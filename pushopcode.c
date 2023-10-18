#include "monty.h"

/**
 * push - Pushes element onto the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_count: Line num in the Monty byte code file
 */

void push(stack_t **stack, unsigned int line_count)
{
	char *arg = strtok(NULL, " \t\n");
	int a, i;

	stack_t *new_node;

	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_count);
		exit(EXIT_FAILURE);
	}

	a = atoi(arg);

	for (i = 0; arg[i] != '\0'; i++)
	{
		if (arg[i] < '0' || arg[i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_count);
			 exit(EXIT_FAILURE);
		}
	}
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = a;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
