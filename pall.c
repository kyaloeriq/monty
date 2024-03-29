#include "monty.h"
/**
 * pall - displays contents of the stack
 * @stack: pointer to the stack
 * @line_num: line number in the Monty bytecode file
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_num;
}
