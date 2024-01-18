#include "monty.h"

/**
 * do_add_node - add a node to the stack
 * @n_head: head pointer pointing to the first node of the stack
 * @data: data value of the node
*/
void do_add_node(stack_t **n_head, int data)
{
	stack_t *fresh_node, *traverser;

	traverser = *n_head;

	fresh_node = malloc(sizeof(stack_t));
	if (fresh_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (traverser != NULL)
		traverser->prev = fresh_node;

	fresh_node->n = data;
	fresh_node->prev = NULL;
	fresh_node->next = *n_head;
	*n_head = fresh_node;
}
