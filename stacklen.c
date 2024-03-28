#include "monty.h"

/**
 * getlen - func to get the len of stack
 * @stack: is our stack to c
 * Return: the exact leng of stack
 */

int getlen(stack_t *stack)
{
	stack_t *temp;
	int len = 0;

	temp = stack;

	while (temp)
	{
		temp = temp->next;
		len++;
	}

	return (len);
}

