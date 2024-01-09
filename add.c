#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line: line number
 * Return: void
 */
void _add(stack_t **stack, unsigned int line)
{
	int result, first, second;
	stack_t *top;

	top = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	first = top->n;
	second = top->next->n;
	result = first + second;
	top->next->n = result;
	*stack = top->next;
	free(top);
}
