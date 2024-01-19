#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_num: line number in the file
 * @value_str: element to be pushed
 */
void push(stack_t **stack, unsigned int line_num, char *value_str)
{
	int value;
	stack_t *new_node;

	/*Parsing of argument from the line*/
	value = atoi(value_str);
	if (value == 0 && value_str[0] != '0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	/*Creating a new stack node and setting value*/
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->next = *stack; /*New node's next pointer to the current top*/
	*stack = new_node; /*Update the stack's top to the new node*/
}
