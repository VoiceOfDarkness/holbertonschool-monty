#include "monty.h"
/**
 * _pop - prints top of stack
 * @stack: input stack
 * @line: number of line
 */
void _pop(stack_t **stack, unsigned int line)
{
	stack_t *temp = *stack;

	if (stack && *stack)
	{
		*stack = (*stack)->next;
		free(temp);
		return;
	}
	fprintf(stderr, "L%u: can't pop an empty stack\n", line);
	exit(EXIT_FAILURE);
}
