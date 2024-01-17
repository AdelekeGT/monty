#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

#define MONTY_DELIM "\n\t "
#define CONTENT_SIZE 50
#define BUFSIZE 1024
#define INIT {NULL, NULL, 0, NULL}

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct MontyData - data for command passed in to be executed
 * @m_file: monty file opened using fopen()
 * @file_content: content of opened file
 * @st_switch: change from stack to queue
 * @argu: arguments
*/
typedef struct MontyData
{
	FILE *m_file;
	char *file_content;
	int st_switch;
	char *argu;
} MontyPack;

extern MontyPack monty_object;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/* FUNCTIONS */
int main(int argc, char **argv);
void do_instructions(char *content, stack_t **h, int line_cnt, FILE *m_file);
void _error_write(char *err_str);
void stack_freer(stack_t **h);
char *makeshift_itoa(int integer);

ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

void do_add_node(stack_t **n_head, int data);
void do_join_queue(stack_t **n_head, int data);

void do_push(stack_t **n_head, unsigned int line_number);
void do_pall(stack_t **n_head, unsigned int line_number);
void do_pint(stack_t **n_head, unsigned int line_number);
void do_pop(stack_t **n_head, unsigned int line_number);
void all_free(FILE *the_file, char *file_content, stack_t **the_stack);
void do_swap(stack_t **n_head, unsigned int line_number);
void do_add(stack_t **n_head, unsigned int line_number);
void do_nop(stack_t **n_head, unsigned int line_number);

#endif /* MONTY_H */
