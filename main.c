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

	stack_t *stack = NULL;
	FILE *monty_file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <monty_file>\n", argv[0]);
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
		if (line[0] == '\n' || line[0] == '#')
			continue;
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

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

	opcode = strtok(line, " \t\n");
	arg = strtok(NULL, " \t\n");

	if (opcode != NULL)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (arg == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				success = 0;
			}
			else
			{
				push(stack, atoi(arg));
			}
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack, line_number);
		}
	}

	return (success);
}

/**
 * read_and_task_file - Read and process a Monty byte code file.
 * @file_name: Name of the Monty file.
 * @stack: Pointer to the stack.
 *
 * Return: 1 on success, 0 on failure.
 */

int read_and_task_file(const char *file_name, stack_t **stack)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	int success = 1;

	FILE *monty_file = fopen(file_name, "r");

	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		return (0);
	}

	while ((fgets(line, len, monty_file)) != NULL)
	{
		line_number++;
		success = task_line(line, stack, line_number);
		if (!success)
			break;
	}

	free(line);
	fclose(monty_file);

	return (success);
}
