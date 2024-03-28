#include "monty.h"

/**
 * push - push into the stack
 * @stack: stack_t **
 * @line_number: unsigned int
 * Return: void
*/

void push(stack_t **stack, unsigned int line_number)
{
	if (argument->notokens <= 1 || !(is_nmbr(argument->tokens[1])))
	{
		free_arguments();
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_failed();

	(*stack)->next = (*stack)->prev = NULL;
	(*stack)->n = (int) atoi(argument->tokens[1]);

	if (argument->head != NULL)
	{
		(*stack)->next = argument->head;
		argument->head->prev = *stack;
	}
	argument->head = *stack;
	argument->stack_length += 1;
}

/**
 * is_nmbr - is_nmbr
 * @str: char *
 * Return: int
*/

int is_nmbr(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
		{
			i++;
			continue;
		}
		if (str[i] < '0' || str[i] > '9')
			return (0);

		i++;
	}
	return (1);
}

/**
 * pall - pall
 * @stack: stack_t **
 * @line_number: unsigned int
 * Return: void
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (argument->head == NULL)
		return;

	(void) line_number;
	(void) stack;

	tmp = argument->head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
