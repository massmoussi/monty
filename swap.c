#include "monty.h"

/**
 * op_swap - func swap & second top value in stack
 * @stack: pntr to pntr to stack
 * @counter: numb of line
 */

void op_swap(stack_t **stack, unsigned int counter)
{
	stack_t *temp;
	int length = 0, num;

	length = getlen(*stack);

	if (length >= 2)
	{
		temp = *stack;
		num = temp->n;
		temp->n = temp->next->n;
		temp->next->n = num;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(Taxi.filehold);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
