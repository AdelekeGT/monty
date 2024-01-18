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

	instruction_t struct_arr[] = {
		{"push", do_push}, {"pall", do_pall}, {"pint", do_pint},
		{"pop", do_pop}, {"swap", do_swap}, {"add", do_add},
		{"nop", do_nop}, {"sub", do_minus}, {"div", do_division},
		{"mul", do_multiply}, {"mod", do_modulus}, {"pchar", do_ascii_char},
		{"pstr", do_str_print}, {"stack", do_almighty_stack},
		{"queue", do_almighty_queue}, {"rotl", do_rotl_whatever}, {NULL, NULL}
	};

	token = strtok(content, MONTY_DELIM);
	if (token != NULL && token[0] == '#')
		return;

	monty_object.argu = strtok(NULL, MONTY_DELIM);

	while (token != NULL && struct_arr[iterator].opcode != NULL)
	{
		if (strcmp(struct_arr[iterator].opcode, token) == 0)
		{
			struct_arr[iterator].f(h, line_cnt);
			return;
		}
		iterator++;
	}

	if (token != NULL && struct_arr[iterator].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_cnt, token);
		all_free(m_file, content, *h);
		exit(EXIT_FAILURE);
	}
}
