#include "monty.h"
/**
 * pop -
 * @stack: pointer to stack
 * @line_num: number of line
 */
void pop(stack_t **stack, unsigned int line_num)
{
	if (*stack)
	{
		stack_t *temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

