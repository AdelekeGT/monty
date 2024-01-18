#include "monty.h"

/**
 * do_pint - prints the value at the top of the stack
 * @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_pint(stack_t **n_head, unsigned int line_number)
{
	if (*n_head == NULL)
	{
		do_print_error(1, line_number);
		all_free(monty_object.m_file, monty_object.file_content, *n_head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*n_head)->n);
}
