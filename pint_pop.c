#include "monty.h"

/**
 * pint - print the value of the top
 * @stack: stack_t **
 * @line_number: unsigned int
 * Return: void
*/

void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (argument->head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", argument->head->n);
}

/**
 * pop - delet the top
 * @stack: stack_t **
 * @line_number: unsigned int
 * Return: void
*/

void pop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (argument->head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	delete_stack_node();
	argument->stack_length -= 1;
}

/**
 * delete_stack_node - delete_stack_node
 * Return: void
*/

void delete_stack_node(void)
{
	stack_t *temp;

	temp = argument->head;
	argument->head = temp->next;
	free(temp);
}
