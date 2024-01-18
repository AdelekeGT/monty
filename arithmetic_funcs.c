#include "monty.h"

/**
 * do_minus - subtracts the top element of the stack from the element after it
 * @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_minus(stack_t **n_head, unsigned int line_number)
{
	int tracker = 0, difference;
	stack_t *helper;

	helper = *n_head;

	while (helper != NULL)
	{
		tracker++;
		helper = helper->next;
	}

	if (tracker <= 1)
	{
		do_print_error(5, line_number);
		all_free(monty_object.m_file, monty_object.file_content, *n_head);
		exit(EXIT_FAILURE);
	}

	helper = *n_head;

	difference = helper->next->n - helper->n;
	helper->next->n = difference;
	*n_head = helper->next;
	free(helper);
}

/**
 * do_division - divides the second top element of the stack by the top element
 *  @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_division(stack_t **n_head, unsigned int line_number)
{
	stack_t *traverser;
	int division, stack_length = 0;

	traverser = *n_head;

	while (traverser != NULL)
	{
		stack_length++;
		traverser = traverser->next;
	}

	if (stack_length <= 1)
	{
		do_print_error(6, line_number);
		all_free(monty_object.m_file, monty_object.file_content, *n_head);
		exit(EXIT_FAILURE);
	}

	traverser = *n_head;

	if (traverser->n == 0)
	{
		do_print_error(7, line_number);
		all_free(monty_object.m_file, monty_object.file_content, *n_head);
		exit(EXIT_FAILURE);
	}

	division = traverser->next->n / traverser->n;
	traverser->next->n = division;
	*n_head = traverser->next;
	free(traverser);
}

/**
 * do_multiply - multiplies the second top element of the stack
 * with the top element
 *  @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_multiply(stack_t **n_head, unsigned int line_number)
{
	stack_t *traverser;
	int stack_length = 0, multiply;

	traverser = *n_head;

	while (traverser != NULL)
	{
		stack_length++;
		traverser = traverser->next;
	}

	if (stack_length <= 1)
	{
		do_print_error(8, line_number);
		all_free(monty_object.m_file, monty_object.file_content, *n_head);
		exit(EXIT_FAILURE);
	}

	traverser = *n_head;

	multiply = traverser->next->n * traverser->n;
	traverser->next->n = multiply;
	*n_head = traverser->next;
	do_pop(n_head, line_number);
}

/**
 * do_modulus -  computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 *  @n_head: pointer pointing to the first node of list
 * @line_number: line number
*/
void do_modulus(stack_t **n_head, unsigned int line_number)
{
	int stack_length = 0, the_remainder;
	stack_t *traverser;

	traverser = *n_head;

	while (traverser != NULL)
	{
		traverser = traverser->next;
		stack_length++;
	}

	if (stack_length <= 1)
	{
		do_print_error(9, line_number);
		all_free(monty_object.m_file, monty_object.file_content, *n_head);
		exit(EXIT_FAILURE);
	}

	traverser = *n_head;

	if (traverser->n == 0)
	{
		do_print_error(7, line_number);
		all_free(monty_object.m_file, monty_object.file_content, *n_head);
		exit(EXIT_FAILURE);
	}

	the_remainder = traverser->next->n % traverser->n;
	traverser->next->n = the_remainder;
	*n_head = traverser->next;
	do_pop(n_head, line_number);
}
