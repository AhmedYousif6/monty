#include "monty.h"

/**
 * main - the main func to run the program.
 * @argc: number of command line arguments.
 * @argv: command line arguments.
 * Return: 0 always success.
 */
int main(int argc, char **argv)
{

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	interp(argv[1]);

	return (0);
}
