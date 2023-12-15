#include "monty.h"

/**
 * _push - add data at the top (stack).
 * @stack: pointer to  pointer to linked list.
 * @line_number: number of line in a file.
 * Return: nothing.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *str_value;
	int value;
	stack_t *new_node;

	str_value = strtok(NULL, " \n\t");
	if (str_value == NULL || !isdigit(str_value[0]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(str_value);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}


/**
 * _pall - prints all the data from top to buttom.
 * @stack: pointer to pointer to linked list.
 * @line_number: number of line in the file.
 * Return: nothing.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pint - print the most top data in the stack.
 * @stack: pointer to pointer to linked list.
 * @line_number: line num of the file.
 * Return: nothing.
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - remove the top element of the stack.
 * @stack: pointer to pointer to linked list.
 * @line_number: line num of the file.
 * Return: nothing.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * _swap - swap the top two elements of the stack.
 * @stack: pointer to pointer to linked list.
 * @line_number: line num of the file.
 * Return: nothing.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = *stack;
	}
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
