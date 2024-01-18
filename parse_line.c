#include <string.h>
#include "monty.h"
/**
 * parse_line - parses a line into an instruction
 * @line: line
 * Return: instr
 */
instruction_t parse_line(char line[1024])
{
	instruction_t instr;
	instr.opcode = strtok(line, " \t\n");

	if (instr.opcode)
	{
		instr.arg = strtok(NULL, " \t\n");
	}
	else
	{
		instr.arg = NULL; /*Set to NULL if opcode is not present*/
	}
	return (instr);
}
