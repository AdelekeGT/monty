#include "monty.h"

/**
 * do_instructions - takes in read file content for processing
 * @content: content of read file extracted by getline()
 * @h: pointer pointing to head node
 * @line_cnt: number of line
 * @m_file: pointer to monty file opened with fopen()
*/
void do_instructions(char *content, stack_t **h, int line_cnt, FILE *m_file)
{
	char *token;
	int iterator = 0;
	char line_no_str[10];

	instruction_t struct_arr[] = {
		{"push", do_push}, {"pall", do_pall}, {"pint", do_pint},
		{"pop", do_pop}, {"swap", do_swap}, {"add", do_add},
		{"nop", do_nop}, {NULL, NULL}
	};

	token = strtok(content, MONTY_DELIM);
	if (token != NULL && token[0] == '#')
		return;

	monty_object.argu = strtok(NULL, MONTY_DELIM);

	while (token != NULL && struct_arr[iterator++].opcode != NULL)
	{
		if (strcmp(struct_arr[iterator].opcode, token) == 0)
			struct_arr[iterator].f(&(*h), line_cnt);
	}

	if (token != NULL && struct_arr[iterator].opcode == NULL)
	{
		sprintf(line_no_str, "%d", line_cnt);
		_error_write("L");
		_error_write(line_no_str);
		_error_write(":d unknown instruction ");
		_error_write(token);
		_error_write("\n");
		fclose(m_file);
		free(content);
		stack_freer(h);
		exit(EXIT_FAILURE);
	}
}
