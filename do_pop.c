#include "monty.h"

/**
 * do_pop - removes the top element of the stack
 * @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_pop(stack_t **n_head, unsigned int line_number)
{
	stack_t *popper;

	if (*n_head == NULL)
	{
		do_print_error(2, line_number);
		all_free(monty_object.m_file, monty_object.file_content, *n_head);
		exit(EXIT_FAILURE);
	}

	popper = *n_head;
	*n_head = (*n_head)->next;
	free(popper);
}
