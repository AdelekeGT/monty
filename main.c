#define _GNU_SOURCE
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
	FILE *monty_file;
	char *file_content = NULL;
	size_t getline_size = 0;
	ssize_t bytes_read = 1;
	unsigned int num_of_line = 0;
	stack_t *n_head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	monty_object.m_file = monty_file;
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (bytes_read > 0)
	{
		bytes_read = getline(&file_content, &getline_size, monty_file);
		monty_object.file_content = file_content;
		num_of_line++;

		if (bytes_read > 0)
			do_instructions(file_content, &n_head, num_of_line, monty_file);

		free(file_content);
		file_content = NULL;
	}

	stack_freer(n_head);
	fclose(monty_file);

	return (0);
}
