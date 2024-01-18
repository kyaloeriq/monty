#include "monty.h"
/**
 * sub - subtracts the top element of the stack
 * @stack: pointer to stack
 * @line_num: number of line
 */
void sub(stack_t **stack, unsigned int line_num)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_num); /*Remove the top element*/
}
