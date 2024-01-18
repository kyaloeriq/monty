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
	instr.arg = strtok(NULL, " \t\n");
	return (instr);
}
