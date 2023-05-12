#include "monty.h"
/**
 * execute_instructions - Reads a file line by line and executes
 *
 * @file: Pointer to the file to be read.
 * @stack: Double pointer to the stack.
 */
void execute_instructions(FILE *file, stack_t **stack)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int i;
	char *opcode;
	unsigned int line_number = 0;

	static const instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		if (line[read - 1] == '\n')
		line[read - 1] = '\0';
		opcode = strtok(line, "\t\r ");

		if (opcode == NULL)
			continue;


		for (i = 0; instructions[i].opcode; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(stack, line_number);
				break;
			}
		}

			if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
}
/**
 * parse_arg - Parses the argument to ensure it's a valid integer.
 * @arg: The argument string to parse.
 * @line_number: The line number for error reporting.
 *
 * Return: The parsed integer.
 */
int parse_arg(char *arg, unsigned int line_number)
{
	char *ptr;
	int n = (int)strtol(arg, &ptr, 10);

	if (ptr == arg || *ptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	return (n);
}

/**
 * add_node - Adds a new node to the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @n: The integer to add to the stack.
 */
void add_node(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * _isdigit - Checks if a string represents a valid (possibly signed) integer.
 * @str: The string to check.
 *
 * string to ensure it's a digit.
 *
 * Return: 1 if the string represents a valid integer, 0 otherwise.
 */
int _isdigit(char *str)
{
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; str[i]; i++)
	{
		if (isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}
/**
 * open_file - Opens a file for reading and handles errors.
 *
 * @filename: Name of the file to be opened.
 *
 * Return: A pointer to the opened file.
 */
FILE *open_file(char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (file);
}
