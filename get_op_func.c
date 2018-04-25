#include "monty.h"

/**
 * get_op_func - function to select correct operation function
 * @token1: 1st bytecode input (opcode)
 * Return: pointer to correct operation function
 */
void (*get_op_func(char *token1))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction_s[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;

	while (instruction_s[i] != NULL)
	{
		if (*token1 == instruction_s[i].opcode)
			return (instruction_s[i].f);
		i++;
	}
	return (NULL);
}
