#include "monty.h"

/**
 * do_swap - function swaps the top two elements of the stack
 * @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_swap(stack_t **n_head, unsigned int line_number)
{
	stack_t *swapper;
	int list_len = 0, makeshift;

	swapper = *n_head;

	while (swapper != NULL)
	{
		list_len++;
		swapper = swapper->next;
	}

	if (list_len <= 1)
	{
		do_print_error(3, line_number);
		all_free(monty_object.m_file, monty_object.file_content, *n_head);
		exit(EXIT_FAILURE);
	}

	swapper = *n_head;

	makeshift = swapper->n;
	swapper->n = swapper->next->n;
	swapper->next->n = makeshift;
}
