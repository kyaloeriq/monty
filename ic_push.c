#include "monty.h"

void push(stack_t **stack, unsigned int line_num, int value)
{
	stack_t *new_node;

	/*Parsing of argument from the line*/
	if (value == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	/*Creating a new stack node and setting value*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->next = *stack; /*New node's next pointer to the current top*/
	*stack = new_node; /*Update the stack's top to the new node*/


