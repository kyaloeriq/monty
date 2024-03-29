#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * exec_instruc - executes instructions
 * @instr: opcode
 * @stack: pinter to stack
 * @line_num: number where instruction appears
 */
void exec_instruc(instruction_t instr, stack_t **stack, unsigned int line_num)
{
	int value;
	char value_str[12];

	if (!instr.opcode)
		return;
	if (strcmp(instr.opcode, "push") == 0)
	{
		if (!instr.arg)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		} value = atoi(instr.arg);
		if (value == 0 && instr.arg[0] != '0')
		{	fprintf(stderr, "L%u: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		} sprintf(value_str, "%d", value);
		push(stack, line_num, value_str); }
	else if (strcmp(instr.opcode, "pall") == 0)
		pall(stack, line_num);
	else if (strcmp(instr.opcode, "pint") == 0)
		pint(stack, line_num);
	else if (strcmp(instr.opcode, "pop") == 0)
		pop(stack, line_num);
	else if (strcmp(instr.opcode, "swap") == 0)
		swap(stack, line_num);
	else if (strcmp(instr.opcode, "add") == 0)
		add(stack, line_num);
	else if (strcmp(instr.opcode, "nop") == 0)
		nop(stack, line_num);
	else if (strcmp(instr.opcode, "sub") == 0)
		sub(stack, line_num);
	else if (strcmp(instr.opcode, "div") == 0)
		monty_div(stack, line_num);
	else if (strcmp(instr.opcode, "mul") == 0)
		monty_mul(stack, line_num);
	else if (strcmp(instr.opcode, "mod") == 0)
		monty_mod(stack, line_num);
	else	/*Handles unknown opcode*/
	{	fprintf(stderr, "L%u: unknown opcode %s\n", line_num, instr.opcode);
		exit(EXIT_FAILURE); } }
