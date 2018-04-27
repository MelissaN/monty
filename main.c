#include "monty.h"

/**
 * main - entry into interpreter
 * @argc: argc counter
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	unsigned int line = 1;
	size_t len = 0;
	char *token, *args = NULL;
	stack_t *h = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	while (getline(&args, &len, fp) != -1)
	{
		if (*args == '\n')
		{
			line++;
			continue;
		}
		token = strtok(args, "\n\t\a\r ;:");
		if (token)
		{
			if (strcmp(token, "push") == 0)
			{
				token = strtok(NULL, "\n\t\a\r ;:");
				push(&h, line, token);
				continue;
			}
			else
			{
				if (get_op_func(token) != 0)
					get_op_func(token)(&h, line);
				else
				{
					free_dlist(&h);
					printf("L%d: unknown instruction %s\n", line, token);
					exit(EXIT_FAILURE);
				}
			}
		}
		line++;
	}
	free_dlist(&h);
	return (0);
}
