#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: stack
 * @line_num: line to be parsed
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
}
