#include "monty.h"

/**
 * do_pall - prints all values on the stack startinf from the top
 * @stack: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;

	if ((*stack)->next == NULL)
		printf("%d\n", (*stack)->n);

	if ((*stack)->next != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;

		while (temp->prev != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
		}
	}
}
