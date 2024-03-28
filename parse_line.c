#include "monty.h"

/**
 * tok_command - function to parse the line
 * Return: void
*/

void tok_command(void)
{
	int i = 0;
	char *cmnd_cpy = NULL;
	char *token = NULL;
	char *delim = " \n";

	cmnd_cpy = malloc(sizeof(char) * (strlen(argument->line) + 1));
	strcpy(cmnd_cpy, argument->line);
	argument->notokens = 0;
	token = strtok(cmnd_cpy, delim);
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		argument->notokens += 1;
	}

	argument->tokens = malloc(sizeof(char *) *
	(argument->notokens + 1));/*need to be free*/
	strcpy(cmnd_cpy, argument->line);
	token = strtok(cmnd_cpy, delim);
	while (token != NULL)
	{
		argument->tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (argument->tokens[i] == NULL)
		{
			malloc_failed();
		}
		strcpy(argument->tokens[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	argument->tokens[i] = NULL;
	free(cmnd_cpy);
}

/**
 * close_file - close_file
 * Return: void
*/

void close_file(void)
{
	if (argument->file == NULL)
	{
		return;
	}

	fclose(argument->file);
	argument->file = NULL;
}
