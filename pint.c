#include "monty.h"

/**
 * f_pint - func print the element of stack
 * @stack: pntr to pntr to our stack
 * @counter: numb of line
 */

void op_pint(stack_t **stack, unsigned int counter)
{
	int top = 0;

	if (*stack != NULL)
	{
		top = (*stack)->n;
		printf("%d\n", top);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
		fclose(Taxi.filehold);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
