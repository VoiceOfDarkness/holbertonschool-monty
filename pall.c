#include "monty.h"

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
