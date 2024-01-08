#include "monty.h"

/**
 * _pall - prints all the values on the stack, starting from the top
 * @stack: pointer to the head of the stack
 * @line: line number
 * Return: void
 */
void _pall(stack_t **stack, unsigned int __attribute__((unused)) line)
{
	int idx = 0;
	stack_t *cur;

	cur = *stack;
	while (cur)
	{
		if (cur != NULL)
		printf("%d\n", cur->n);
		idx++;
		cur = cur->next;
	}
}
