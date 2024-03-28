#include "monty.h"

/**
 * execut_line - instr for first token
 * Return: void
*/

void execut_line(void)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", &push},
		{"pall", &pall},
		{"pop", &pop},
		{"pint", &pint},
		/**
		*{"swap", &swap},
		*{"nop", &nop},
		*{"add", &add},
		*{"sub", &sub},
		*{"div", &_div},
		*{"mul", &mul},
		*{"rotl", &rotl},
		*{"rotr", &rotr},
		*{"stack", &stack},
		*/
	};

	if (argument->notokens == 0)
	{
		return;
	}
	for (; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, argument->tokens[0]) == 0)
		{
			argument->instruct->opcode = instructions[i].opcode;
			argument->instruct->f = instructions[i].f;
			return;
		}
	}
	instruction_error();
}

/**
 * run_instruction - run instruction
 * Return: void
*/

void run_instruction(void)
{
	stack_t *stack = NULL;

	if (argument->notokens == 0)
	{
		return;
	}

	argument->instruct->f(&stack, argument->lineNum);
}
