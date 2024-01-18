#include "monty.h"

/**
 * do_minus - subtracts the top element of the stack from the element after it
 * @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_minus(stack_t **n_head, unsigned int line_number)
{
	int tracker = 0, difference;
	stack_t *helper;

	helper = *n_head;

	while (helper != NULL)
	{
		tracker++;
		helper = helper->next;
	}

	if (tracker <= 1)
	{
		do_print_error(5, line_number);
		all_free(monty_object.m_file, monty_object.file_content, *n_head);
		exit(EXIT_FAILURE);
	}

	helper = *n_head;

	difference = helper->next->n - helper->n;
	helper->next->n = difference;
	*n_head = helper->next;
	do_pop(n_head, line_number);
}
