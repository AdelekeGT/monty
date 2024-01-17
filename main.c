#include "monty.h"
MontyPack monty_object = INIT;

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
	ssize_t bytes_read;
	unsigned int num_of_line = 0;
	stack_t *n_head = NULL;

	if (argc != 2)
	{
		_error_write("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	monty_object.m_file = monty_file;
	if (monty_file == NULL)
	{
		_error_write("Error: Can't open file ");
		_error_write(argv[1]);
		_error_write("\n");
		exit(EXIT_FAILURE);
	}

	bytes_read = getline(&file_content, &getline_size, monty_file);
	while (bytes_read != -1)
	{
		monty_object.file_content = file_content;
		num_of_line++;

		if (bytes_read > 0)
			do_instructions(file_content, &n_head, num_of_line, monty_file);

		free(file_content);
	}

	free(n_head);
	fclose(monty_file);
	free(file_content);
	return (0);
}
