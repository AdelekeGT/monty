#define _GNU_SOURCE
#include "monty.h"

/**
 * do_process_file - open file and do processing
 * @arg: argument from **argv
*/
void do_process_file(char *arg)
{
	FILE *monty_file;
	char *file_content = NULL;
	size_t getline_size = 0;
	ssize_t bytes_read = 1;
	unsigned int num_of_line = 0;
	stack_t *n_head = NULL;

	monty_file = fopen(arg, "r");
	monty_object.m_file = monty_file;
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arg);
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

}
