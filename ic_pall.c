#include "monty.h"
/**
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_num; 
}
