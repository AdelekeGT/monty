#include "monty.h"

/**
 * all_free - free file descriptor, content and stack
 * @the_file: file stream
 * @file_content: the contents of file
 * @the_stack: stack to be freed
*/
void all_free(FILE *the_file, char *file_content, stack_t *the_stack)
{
	fclose(the_file);
	free(file_content);
	stack_freer(the_stack);
}
