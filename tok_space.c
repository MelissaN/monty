#include "monty.h"
/**
 * tok_space - removes spaces
 * @line: string to tokenize
 * Return: array of strings
 */
char *token_line(stack_t **h, unsigned int n)
{
	int i;
	stack_t *args;

	if (args == NULL)
	{
		free(args);
		exit(1);
	}
	args = *h;
	i = 0;
	args[i] = strtok(line, " ");
	while (args[i] != NULL)
	{
		i++;
		args[i] = strtok(NULL, " ");
	}
	(void) n;
	return (args);
}
