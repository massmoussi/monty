#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: pnts to the previous elem of the stack (or queue)
 * @next: pnts to the nxt elem of the stack (or queue)
 *
 * Description: doubly linked list nde struct
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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct taxi_t - struct hold some data so I can call it in other files
 * @filehold: hold file pointer
 * @arg: hold number(as string)
 *
 * Description: struct to faciliate the data calling
 */
typedef struct taxi_t
{
	FILE *filehold;
	char *arg;
} taxi_t;

extern taxi_t Taxi;

char *tokenize(char *content, char **op);
bool is_valid_integer(const char *str);
int getlen(stack_t *stack);
int execute_instruction(char *op, stack_t **stack, unsigned int counter);
void op_push(stack_t **stack, unsigned int counter);
void op_pall(stack_t **stack, unsigned int counter);
void op_pint(stack_t **stack, unsigned int counter);
void op_pop(stack_t **stack, unsigned int counter);
void op_swap(stack_t **stack, unsigned int counter);
void op_add(stack_t **stack, unsigned int counter);
void op_sub(stack_t **stack, unsigned int counter);
void op_div(stack_t **stack, unsigned int counter);
void op_mul(stack_t **stack, unsigned int counter);
void op_nop(stack_t **stack, unsigned int counter);
void op_mod(stack_t **stack, unsigned int counter);
void free_stack(stack_t *h);

#define BUFF 1024

#endif /* MONTY_H  */
