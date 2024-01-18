#include "monty.h"

/**
 * do_join_queue - add a node to the queue
 * @data: data part of node
 * @n_head: head pointer pointing to the first node
*/
void do_join_queue(stack_t **n_head, int data)
{
	stack_t *fresh_node, *traverser;

	traverser = *n_head;

	fresh_node = malloc(sizeof(stack_t));
	if (fresh_node == NULL)
	{
		_error_write("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	fresh_node->next = NULL;
	fresh_node->n = data;

	if (traverser != NULL)
	{
		while (traverser->next != NULL)
			traverser = traverser->next;

		traverser->next = fresh_node;
		fresh_node->prev = traverser;
	}
	else
	{
		*n_head = fresh_node;
		(*n_head)->prev = NULL;
	}
}
