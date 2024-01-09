#include "monty.h"
/**
 * _pint - prints top of stack
 * @stack: input stack
 * @line: number of line
 */
void _pint(stack_t **stack, unsigned int line)
{
	if (stack && *stack)
	{
		printf("%d\n", (*stack)->n);
		return;
	}
	fprintf(stderr, "L%u: can't pint, stack empty\n", line);
	exit(EXIT_FAILURE);
}
