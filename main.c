#include <stdio.h>
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
	size_t len = 0;
	unsigned int line_num = 0;
	FILE *file;
	global_stack = NULL;

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
	/*Parse file and execute instructions*/
	while (fgets(line, len, file) != NULL)
	{
		line_num++;
	}
	/*Clean up and close file*/
	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}

