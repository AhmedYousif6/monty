#include "monty.h"

/**
 * _add - add the top two elements of the stack.
 * @stack: pointer to pointer to linked list.
 * @line_number: line num of the file.
 * Return: nothing.
*/
void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number);
}


/**
 * _nop - do nothing.
 * @stack: pointer to pointer to linked list.
 * @line_number: line num of the file.
 * Return: nothing.
*/

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
