#include "monty.h"

/**
 * op_div - divide sec element to top element
 * @stack: pntr to pntr to our stack
 * @counter: numb of line
 */

void op_div(stack_t **stack, unsigned int counter)
{
	int res = 0, length;
	stack_t *node;

	length = getlen(*stack);
	if (length >= 2)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", counter);
			fclose(Taxi.filehold);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		res = (*stack)->next->n / (*stack)->n;
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(Taxi.filehold);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
