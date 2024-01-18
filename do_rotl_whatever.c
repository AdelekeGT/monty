#include "monty.h"

/**
 * do_rotl_whatever - rotates the stack to the top.
 * @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_rotl_whatever(stack_t **n_head, unsigned int line_number)
{
	stack_t *traverser;

	traverser = *n_head;

	while (traverser != NULL)
		traverser = traverser->next;

	if (*n_head != NULL)
	{
		traverser->next = *n_head;
		(*n_head)->prev = traverser;
		traverser = traverser->next;
		*n_head = (*n_head)->next;
		traverser->next = NULL;
	}
}
