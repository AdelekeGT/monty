#include "monty.h"

/**
 * do_push - function pushes an element to the stack
 * @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_push(stack_t **n_head, unsigned int line_number)
{
	int push_arg, i_i = 0, _k, not_int;

	if (monty_object.argu != NULL)
	{
		if (monty_object.argu[0] == '-')
			i_i++;
		for (_k = i_i; monty_object.argu[_k] != '\0'; _k++)
		{
			if (!isdigit(monty_object.argu[_k]))
				not_int = 1;
		}
	}

	if (monty_object.argu == NULL || not_int == 1)
	{
		do_print_error(0, line_number);
		all_free(monty_object.m_file, monty_object.file_content, n_head);
		exit(EXIT_FAILURE);
	}

	push_arg = atoi(monty_object.argu);

	if (monty_object.st_switch == 0)
		do_add_node(n_head, push_arg);
	else
		do_join_queue(n_head, push_arg);
}
