#include "monty.h"

/**
 * do_push - function pushes an element to the stack
 * @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_push(stack_t **n_head, unsigned int line_number)
{
	int push_arg, i_i = 0, _k, not_int;
	char line_no_str[10];

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
		sprintf(line_no_str, "%u", line_number);
		_error_write("L");
		_error_write(line_no_str);
		_error_write(": usage: push integer\n");
		fclose(monty_object.m_file);
		free(monty_object.file_content);
		stack_freer(n_head);
		exit(EXIT_FAILURE);
	}

	push_arg = atoi(monty_object.argu);

	if (monty_object.st_switch == 0)
		do_add_node(n_head, push_arg);
	else
		do_join_queue(n_head, push_arg);
}
