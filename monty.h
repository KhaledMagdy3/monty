#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

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

/**
 * struct arg_s - hold var
 * @file: file for stream from file
 * @line: string from stream
 *
 * Description: hold varuables
*/
typedef struct arg_s
{
	FILE *file;
	char *line;
	char **tokens;
	unsigned int lineNum;
	int notokens;
	int stack_length;
	int stack;
	instruction_t *instruct;
	stack_t *head;
} arg_t;

extern arg_t *argument;

void init_arguments();
void malloc_failed();
void validate_arguments(int argc);
void get_filename_failed(char *filename);
void get_filename(char *filename);
void tok_command(void);
void execut_line (void);
void instruction_error(void);
void free_tokens(void);
void close_file(void);
void run_instruction(void);
void free_arguments();
void free_head(void);
void free_stack(stack_t *head);
void free_all_args(void);
void push(stack_t **stack, unsigned int line_number);
int is_nmbr(char *str);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void delete_stack_node(void);

#endif /*MONTY_H*/