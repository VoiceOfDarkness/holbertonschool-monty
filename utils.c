#include "monty.h"

/**
 * check_num - check if a string is a number
 * @opcode: string to check
 * Return: 1 if true, 0 if false
*/
int check_num(char *opcode)
{
	unsigned int idx = 0;

	if (opcode == NULL)
		return (0);

	while (opcode[idx])
	{
		if (opcode[0] == '-')
		{
			idx++;
			continue;
		}
		if (!isdigit(opcode[idx]))
			return (0);
		idx++;
	}

	return (1);
}

/**
 * free_stack - free a stack
 * @head: head of the stack
 * Return: void
*/
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * get_code - get the code from a file
 * @stream: file to read
 * @stack: stack to use
 * Return: void
*/
void get_code(FILE *stream, stack_t **stack)
{
	char *opcode, *token = NULL;
	size_t size = 0;
	int count = 0;

	while (getline(&opcode, &size, stream) != -1)
	{
		count++;
		token = strtok(opcode, " \n\t\r");
		if (token == NULL || *token == '#')
			continue;

		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \n\t\r");
			_push(token, stack, count);
		}
		else
		{
			get_opc(token, stack, count);
		}
	}
	free(opcode);
}

/**
 * get_opc - get the opcode
 * @opcode: opcode to get
 * @cp_stack: stack to use
 * @line: line of the opcode
 * Return: void
*/
void get_opc(char *opcode, stack_t **cp_stack, unsigned int line)
{
	int idx = 0;

	instruction_t function[] = {
		{"pall", _pall},
		{NULL, NULL}
	};

	while (function[idx].opcode)
	{
		if (strcmp(function[idx].opcode, opcode) == 0)
		{
			function[idx].f(cp_stack, line);
			break;
		}
		idx++;
	}

	if (function[idx].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
		exit(EXIT_FAILURE);
	}
}
