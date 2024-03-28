#include "monty.h"

/**
 * free_tokens - free tokens
 * Return: void
*/

void free_tokens(void)
{
	int i = 0;

	if (argument->tokens == NULL)
	{
		return;
	}

	while (argument->tokens[i])
	{
		free(argument->tokens[i]);
		i++;
	}
	free(argument->tokens);
	argument->tokens = NULL;
}

/**
 * free_arguments - free_arguments
*/

void free_arguments(void)
{
	if (argument == NULL)
		return;

	if (argument->instruct)
	{
		free(argument->instruct);
		argument->instruct = NULL;
	}

	free_head();

	if (argument->line)
	{
		free(argument->line);
		argument->line = NULL;
	}
	free(argument);
}

/**
 * free_head - free_head
 * Return: void
*/

void free_head(void)
{
	if (argument->head)
	{
		free_stack(argument->head);
	}
	argument->head = NULL;
}

/**
 * free_stack - free stack
 * @head: stack_t *
 * Return: void
*/

void free_stack(stack_t *head)
{
	if (head == NULL)
		return;

	if (head->next != NULL)
	{
		free_stack(head->next);
	}
	free(head);
}

/**
 * free_all_args - free_all_args
 * Return: void
*/

void free_all_args(void)
{
	close_file();
	free_tokens();
	free_arguments();
}
