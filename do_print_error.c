#include "monty.h"

/**
 * do_print_error - handle errors
 * @error_num: error number to print a specific error message
 * @line_num: line number
*/
void do_print_error(int error_num, unsigned int line_num)
{
	if (error_num == 0)
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
	else if (error_num == 1)
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
	else if (error_num == 2)
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
	else if (error_num == 3)
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
	else if (error_num == 4)
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
}
