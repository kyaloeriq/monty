#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * process_line - Processes line and executes operation
 * @line: line
 * @stack: pinter to stack
 * @line_num: number where instruction appears
 */
void process_line(char line[1024], stack_t **stack, unsigned int line_num)
{
	char *opcode, *arg;
	int value;

	/*Tokenizes line to extract opcode and argument*/
	opcode = strtok(line, " \t\n");
	arg = strtok(NULL, " \t\n");

	if (opcode != NULL)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (arg == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_num);
				exit(EXIT_FAILURE);
			}
			value = atoi(arg); /*Convert argument to an integer*/
			if (value == 0 && strcmp(arg, "0") != 0)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_num);
				exit(EXIT_FAILURE);
			} /*Call the push function*/
			push(stack, line_num, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack, line_num);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(stack, line_num);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(stack, line_num);
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(stack, line_num);
		}
		else
		{ /*Handles unknown opcode*/
			fprintf(stderr, "Error: Unknown opcode %s\n", opcode);
			exit(EXIT_FAILURE);
		}
	}
}
