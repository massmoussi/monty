#include "monty.h"

/**
 * execute_instr - func to ident operation & call other func
 *
 * @op: operation tp or order
 * @stack: pntr to pntr to our stack
 * @counter: line numb in the file
 * Return: 0 if Succed, 1 if fl
 */

int execute_instruction(char *op, stack_t **stack, unsigned int counter)
{
	instruction_t opst[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(Taxi.filehold);
		free(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
