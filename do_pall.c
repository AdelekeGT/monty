#include "monty.h"

/**
 * do_pall - prints all values on the stack starting from the top
 * @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_pall(stack_t **n_head, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *n_head;

	if (*n_head == NULL)
		return;

	if (temp != NULL)
	{
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}
