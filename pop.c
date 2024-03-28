#include "monty.h"


/**
 * op_pop - remv the top element of stack
 * @stack: pntr to pntr to our stack
 * @counter: line numb
 */

void op_pop(stack_t **stack, unsigned int counter)
{
	stack_t *temp;

	if (*stack != NULL)
	{
		temp = *stack;
		*stack = temp->next;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(Taxi.filehold);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
