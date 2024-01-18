#include "monty.h"

/**
 * do_str_print - prints the string starting at the top of the stack
 * @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_str_print(stack_t **n_head, unsigned int line_number)
{
	stack_t *traverser;

	(void)line_number;
	traverser = *n_head;

	if (traverser == NULL)
	{
		printf("\n");
	}
	else
	{
		while (traverser != NULL)
		{
			if ((traverser->n > 0 && traverser->n < 128))
				printf("%c", traverser->n);
			else
				break;
			traverser = traverser->next;
		}
		printf("\n");
	}
}
