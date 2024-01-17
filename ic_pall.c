#include "monty.h"
/**
 * pall - displays contents of the stack
 * @stack: stack
 * @line_num: line parsed
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_num;
}
