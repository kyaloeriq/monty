#include "monty.h"
/**
 * monty_div - divides the second top element
 * @stack: pointer to stack
 * @line_num: number of line
 */
void monty_div(stack_t **stack, unsigned int line_num)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_num);
}
