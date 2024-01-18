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
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	fresh_node->next = NULL;
	fresh_node->n = data;

	if (traverser != NULL)
	{
		while (traverser->next != NULL)
			traverser = traverser->next;

	}

	if (traverser == NULL)
	{
		*n_head = fresh_node;
		(*n_head)->prev = NULL;
	}
	else
	{
		traverser->next = fresh_node;
		fresh_node->prev = traverser;
	}
}
