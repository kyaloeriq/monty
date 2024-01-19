#include "monty.h"
/**
 * monty_mul - multiplies the second top element of the stack
 * @stack: pointer to stack
 * @line_num: number of line
 */
void monty_mul(stack_t **stack, unsigned int line_num)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_num); /*Remove the top element*/
}
