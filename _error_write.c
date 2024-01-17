#include "monty.h"

/**
 * _error_write - uses the write function to print to stderr
 * @err_str: string to be printed
*/
void _error_write(char *err_str)
{
	write(stderr, &err_str, sizeof(err_str) - 1);
}
