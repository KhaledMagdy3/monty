#include "monty.h"

/**
 * malloc_failed - deals with malloc failure
 * Return: void
*/

void malloc_failed(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_arguments();
	exit(EXIT_FAILURE);
}

/**
 * get_filename_failed - deals with filename error
 * @filename: char *
 * Return: void
*/

void get_filename_failed(char *filename)
{
	fprintf(stderr, "Error: Can't open file%s\n", filename);
	free_arguments();
	exit(EXIT_FAILURE);
}

/**
 * instruction_error - invalid instruction
 * Return: void
*/

void instruction_error(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
	argument->lineNum, argument->tokens[0]);
	close_file();
	free_tokens();
	free_arguments();
	exit(EXIT_FAILURE);
}
