#include "monty.h"


/**
 * f_pall - func to print all element in stack
 * @stack: pntr to pntr to our stack
 * @counter: line numb
 * Return: nothg it's a void
 */
void op_pall(stack_t **stack, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
