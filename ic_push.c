#include "monty.h"

void push(stack_t **stack, unsigned int line_num)
{
	/*Parsing of argument from the line*/
	int value;
	if (value == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
}