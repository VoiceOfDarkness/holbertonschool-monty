#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack.
 * @stack: pointer to the head of the stack
 * @line: line number of the opcode
 */
void _swap(stack_t **stack, unsigned int line)
{
	stack_t *current;
	stack_t *node;

	current = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	node = current->next;
	current->next = node->next;
	node->next = *stack;
	current->prev = node;
	node->prev = NULL;
	*stack = node;
}
