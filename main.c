#include "monty.h"

/**
 * free_stack - Frees all elements of a stack.
 * @stack: Pointer to the stack.
 */

void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}

/**
 * main - Start point for the Monty byte code interpreter.
 * @argc: The number of command-line arguments.
 * @argv: The array of command-line arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */


int main(int argc, char *argv[])
{
	char line[1024];
	unsigned int line_number = 0;
	int success = 1;
	size_t line_length;

	stack_t *stack = NULL;
	FILE *monty_file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}


	monty_file = fopen(argv[1], "r");

	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), monty_file) != NULL)
	{
		line_number++;
		line_length = strlen(line);

		if (line_length > 0 && line[line_length - 1] == '\n')
			line[line_length - 1] = '\0';

		success = task_line(line, &stack, line_number);
		if (!success)
			break;
	}
	fclose(monty_file);
	free_stack(stack);

	return (success ? EXIT_SUCCESS : EXIT_FAILURE);
}

/**
 * task_line - Process a single line of Monty byte code.
 * @line: Line of Monty byte code to process.
 * @stack: Pointer to the stack.
 * @line_number: Current line number.
 *
 * Return: 1 on success, 0 on failure.
 */

int task_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode, *arg;
	int success = 1;
	int value;

	opcode = strtok(line, " \t\n");
	arg = strtok(NULL, " \t\n");
	/*
	 * printf(Debug:
	 * Processing line %u. Opcode: %s, Argument: %s\n, line_number, opcode, arg);
	 */
	if (opcode != NULL)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (arg == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer %s\n", line_number, opcode);
				success = 0;
			}
			else
			{
				value = atoi(arg);
				push_to_stack(stack, value);
			}
		}
		else if (strcmp(opcode, "pint") == 0)
			pint(stack, line_number);
		else if (strcmp(opcode, "pall") == 0)
			pall(stack, line_number);
		else if (strcmp(opcode, "pop") == 0)
			pop(stack, line_number);
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			success = 0;
		}
	}
	return (success);
}
