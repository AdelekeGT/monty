#include "monty.h"

/**
 * do_ascii_char - prints the char at the top of the stack
 * @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_ascii_char(stack_t **n_head, unsigned int line_number)
{
	stack_t *traverser;

	traverser = *n_head;

	if (traverser == NULL)
	{
		do_print_error(10, line_number);
		all_free(monty_object.m_file, monty_object.file_content, *n_head);
		exit(EXIT_FAILURE);
	}

	if (traverser->n < 0 || traverser->n >= 128)
	{
		do_print_error(11, line_number);
		all_free(monty_object.m_file, monty_object.file_content, *n_head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", traverser->n);
}
