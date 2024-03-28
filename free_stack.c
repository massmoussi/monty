#include "monty.h"

/**
 * free_stack - func to free stack
 *
 * @h: pntr to our stack
 */

void free_stack(stack_t *h)
{
	stack_t *temp;

	temp = h;
	while (h)
	{
		temp = h->next;
		free(h);
		h = temp;
	}

}
