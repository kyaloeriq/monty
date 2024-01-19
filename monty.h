#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	char *arg;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *global_stack;

void push(stack_t **stack, unsigned int line_num, char *value_str);
void pall(stack_t **stack, unsigned int line_num);
int main(int argc, char *argv[]);
void pint(stack_t **stack, unsigned int line_num);
instruction_t parse_line(char line[1024]);
void exec_instruc(instruction_t instr, stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);
void div(stack_t **stack, unsigned int line_num);

#endif
