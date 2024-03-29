#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 * main - main
 * @argc: argument count
 * @argv: array string
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	unsigned int line_num = 0;
	FILE *file;
	stack_t *stack = NULL;
	instruction_t instr;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line = (char *)malloc(sizeof(char) * 1024);
	if (!line)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	} /*Parse file and execute instructions*/
	while (fgets(line, 1024, file) != NULL)
	{
		line_num++;
		instr = parse_line(line);
		if (!instr.opcode)
		{
			fprintf(stderr, "L%u: unknown instruction (empty line)\n", line_num);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE); }
		exec_instruc(instr, &stack, line_num);
	} /*Clean up and close file*/
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
