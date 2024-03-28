#include "monty.h"

/**
 * op_sub - subt top & sec top element
 * @stack: pointer to pntr to our stack
 * @counter: number of line
 */

void op_sub(stack_t **stack, unsigned int counter)
{
	int sub = 0;
	int length;
	stack_t *node;

	length = getlen(*stack);

	if (length >= 2)
	{
		sub = (*stack)->next->n - (*stack)->n;
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

		node->n = sub;
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(Taxi.filehold);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

}
