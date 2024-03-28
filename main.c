#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

arg_t *argument = NULL;

/**
 * main - main func.
 * @argc: count
 * @argv: value
 * Return: int
*/

int main(int argc, char **argv)
{
	size_t size = 0;
	__ssize_t read;

	validate_arguments(argc);
	init_arguments();
	get_filename(argv[1]);

	while ((read = getline(&argument->line, &size, argument->file)) != -1)
	{
		argument->lineNum += 1;
		tok_command();
		execut_line();
		run_instruction();
		free_tokens();
	}
	close_file();
	free_arguments();

	return (0);
}
