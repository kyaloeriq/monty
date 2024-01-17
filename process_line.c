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

	/*Tokenizes line to extract opcode and argument*/
	opcode = strtok(line, " \t\n");
	arg = strtok(NULL, " \t\n");

	if (opcode != NULL)
	{
		if (strcmp(opcode, "push") == 0)
		{
			push(stack, line_num);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack, line_num);
		}
		else
		{ /*Handles unknown opcode*/
			fprintf(stderr, "Error: Unknown opcode %s\n", opcode);
			exit(EXIT_FAILURE);
		}
	}
}
