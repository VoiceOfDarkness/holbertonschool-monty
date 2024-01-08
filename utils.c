#include "monty.h"

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
	}
	free(opcode);
}
