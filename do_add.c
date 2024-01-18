#include "monty.h"

/**
 * do_add - function adds the top two elements of the stack
 * @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_add(stack_t **n_head, unsigned int line_number)
{
	int makeshift, stack_length = 0;
	stack_t *pointer;

	pointer = *n_head;

	while (pointer != NULL)
	{
		stack_length++;
		pointer = pointer->next;
	}

	if (stack_length <= 1)
	{
		do_print_error(4, line_number);
		all_free(monty_object.m_file, monty_object.file_content, n_head);
		exit(EXIT_FAILURE);
	}

	makeshift = pointer->n + pointer->next->n;
	pointer->next->n = makeshift;
	do_pop(n_head, line_number);

}
