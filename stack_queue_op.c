#include "monty.h"

/**
 * do_almighty_stack - sets format of data to a stack LIFO
 * @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_almighty_stack(stack_t **n_head, unsigned int line_number)
{
	(void)n_head;
	(void)line_number;

	monty_object.st_switch = 1;
}

/**
 * do_almighty_queue - sets format of data to a queue FIFO
 * @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_almighty_queue(stack_t **n_head, unsigned int line_number)
{
	(void)n_head;
	(void)line_number;

	monty_object.st_switch = 2;
}
