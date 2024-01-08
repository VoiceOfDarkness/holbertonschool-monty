#include "monty.h"

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	FILE *stream;
	char *arg;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	arg = argv[1];
	stream = fopen(arg, "r");

	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arg);
		exit(EXIT_FAILURE);
	}

	get_code(stream, &stack);
	free_stack(stack);

	fclose(stream);
	exit(EXIT_SUCCESS);
}
