#include "monty.h"

/**
 * do_push - function pushes an element to the stack
 * @stack: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *fresh_node;
	int push_arg;
	char line_no_str[10];

	fresh_node = malloc(sizeof(stack_t));
	if (fresh_node == NULL)
	{
		_error_write("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	push_arg = atoi(monty_object.argu);
	fresh_node->n = push_arg;

	if (monty_object.argu == NULL || isdigit(push_arg) == 0)
	{
		sprintf(line_no_str, "%u", line_number);
		_error_write("L");
		_error_write(line_no_str);
		_error_write(": usage: push integer\n");
		stack_freer(&(*stack));
	}

	if (*stack == NULL)
	{
		fresh_node->next = NULL;
		*stack = fresh_node;
	}
	else
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = fresh_node;
		fresh_node->next = NULL;
		fresh_node->prev = temp;
	}
}
