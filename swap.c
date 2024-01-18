#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to stack
 * @line_num: number of line
 */
void swap(stack_t **stack, unsigned int line_num)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n  = temp;
}
