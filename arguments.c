#include "monty.h"

/**
 * validate_argument - check number of argc
 * @argc: int count
 * Return: void
*/

void validate_arguments(int argc)
{
	if (argc == 2)
	{
		return;
	}

	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * init_arguments - initialize pointer to arg_t structure
 * Return: void
*/

void init_arguments(void)
{
	argument = malloc(sizeof(arg_t));
	if (argument == NULL)
	{
		malloc_failed();
	}

	argument->instruct = malloc(sizeof(instruction_t));
	if (argument->instruct == NULL)
	{
		malloc_failed();
	}

	argument->file = NULL;
	argument->line = NULL;
	argument->notokens = 0;
	argument->lineNum = 0;
	argument->head = NULL;
	argument->stack_length = 0;
	argument->stack = 1;
}
