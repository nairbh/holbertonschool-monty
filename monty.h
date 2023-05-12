#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


int _isdigit(char *str);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void add_node(stack_t **stack, int n);
void free_stack(stack_t **stack);
void execute_instructions(FILE *file, stack_t **stack);
FILE* open_file(char *filename);
int parse_arg(char *arg, unsigned int line_number);
#endif /* MONTY_H */
