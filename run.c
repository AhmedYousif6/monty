#include "monty.h"
/**
 * interp - func that read instructions from a file and implement functions.
 * @file_name: name of a monty codebyte file.
 * Return: nothing.
 */
void interp(const char *file_name)
{
	char line[256];
	char *token;
	stack_t *stack = NULL;
	size_t x;
	unsigned int line_number = 0;
	int i = 0;
	instruction_t instruc[] = {
		{"push", _push}, {"nop", _nop},
		{"pall", _pall}, {"add", _add},
		{"pint", _pint}, {"swap", _swap},
		{"pop", _pop}, {NULL, NULL}
	};
	FILE *fd = fopen(file_name, "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), fd) != NULL)
	{
		line_number++;
		token = strtok(line, " \n\t");
		if (token == NULL || token[0] == '#')
			continue;
		for (x = 0; instruc[x].opcode != NULL; x++)
		{
			if (strcmp(token, instruc[x].opcode) == 0)
				instruc[x].f(&stack, line_number), i = 1;
			break;
		}
		if (!i)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}
	}
	fclose(fd);
}
