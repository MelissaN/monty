#include "monty.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd, i, ispush = 0, done = 0;
	unsigned int line = 1, line_done;
	ssize_t n_read;
	char *buffer, *token;
	stack_t *h = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char) * 10000);
	if (!buffer)
		return (0);
	n_read = read(fd, buffer, 10000);
	if (n_read == -1)
	{
		free(buffer);
		close (fd);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, "\n\t\a\r ;:");
	while (token != NULL)
	{
		if (done == 1 && line_done == line)
			continue;
		else
			done = 0;
		if (ispush == 1)
		{
			push(&h, line, token);
			ispush = 0;
			token = strtok(NULL, "\n\t\a\r ;:");
			i++; line++;
			continue;
		}
		if (strcmp(token, "push") == 0)
		{
			ispush = 1;
			token = strtok(NULL, "\n\t\a\r ;:");
			i++;
			continue;
		}
		else
		{
		        if (get_op_func(token) != 0)
			{
				get_op_func(token)(&h, line);
				done = 1; line_done = line;
			}
			else
			{
 				free_dlist(&h);
				printf("L%d: unknown instruction %s\n", line, token);
 				exit(EXIT_FAILURE);
 			}
		}
		line++;
		token = strtok(NULL, "\n\t\a\r ;:");
		i++;
	}
	free_dlist(&h); free(buffer);
	close(fd);
	return (0);
}
