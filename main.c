#include "monty.h"

MontyPack monty_object = MONTY_INIT;

/**
 * main - this is the main function
 * @argc: number of arguments passed to command line
 * @argv: pointer to an array of pointers pointing to arguments
 *
 * Return: 0 on success
*/
int main(int argc, char **argv)
{

	if (argc != 2)
	{
		do_print_error(-1, 0);
		exit(EXIT_FAILURE);
	}

	do_process_file(argv[1]);

	return (0);
}
