#include "monty.h"

/**
 * op_mul - mult & second top element
 * @stack: pntr to pntr to our stack
 * @counter: numb of line
 */

void op_mul(stack_t **stack, unsigned int counter)
{
	int res = 0;
	int length;
	stack_t *node;

	length = getlen(*stack);

	if (length >= 2)
	{
		res = (*stack)->n * (*stack)->next->n;
		op_pop(stack, counter);
		op_pop(stack, counter);

		node = malloc(sizeof(stack_t));
		if (node == NULL)
		{
			fprintf(stderr, "L%d: malloc failed\n", counter);
			fclose(Taxi.filehold);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}

		node->n = res;
		node->next = *stack;
		node->prev = NULL;
		if (*stack)
		{
			(*stack)->prev = node;
		}

		*stack = node;
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(Taxi.filehold);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

}
