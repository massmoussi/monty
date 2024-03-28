#include "monty.h"

/**
 * op_mod - calculate modulo of second top element to top element
 * @stack: pointer to pointer to our stack
 * @counter: number of line
 */

void op_mod(stack_t **stack, unsigned int counter)
{
	int mod = 0, length;
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
		mod = (*stack)->next->n % (*stack)->n;
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
		node->n = mod;
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(Taxi.filehold);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
