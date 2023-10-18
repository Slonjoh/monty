#include "monty.h"

/**
 * push - Pushes element onto the stack
 * @line_count: Line num in the Monty byte code file
 */

void push(unsigned int line_count)
{
	char *arg = strtok(NULL, " \t\n");
	int a, i;

	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_count);
		exit(EXIT_FAILURE);
	}

	for (i = 0; arg[i] != '\0'; i++)
	{
		if (!isdigit(arg[i]) && (arg[i] != '-' && i == 0))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_count);
			exit(EXIT_FAILURE);
		}
	}
	a = atoi(arg);
	printf("%d\n", a);
}
