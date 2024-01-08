#include "monty.h"

/**
 * _push - adds a new node at the beginning of a stack_t list.
 * @opcode: opcode
 * @top_stack: top of the stack
 * @line: line number
 * Return: void
 */
void _push(char *opcode, stack_t **top_stack, unsigned int line)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
		return;
	}
	if (check_num(opcode) == 1 && opcode != NULL)
	{
		new->n = atoi(opcode);
		new->next = *top_stack;
		new->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	if (*top_stack != NULL)
		(*top_stack)->prev = new;
	*top_stack = new;
}
