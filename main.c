#include "monty.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd, i, ispush = 0;
	unsigned int line = 1;
	ssize_t n_read, n_wrote;
	char *buffer;
	char *token;
	stack_t *h = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* open/read into buffer */
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

		if (ispush == 1)
		{
//			printf("tok is %d\n", token);
			push(&h, line, token);
		}
		if (strcmp(token, "push") == 0)
		{
			printf("eeeeeee");
			ispush = 1;
			token = strtok(NULL, "\n\t\a\r ;:");
			i++;
			continue;
		}
		line++;
		token = strtok(NULL, "\n\t\a\r ;:");
		i++;
	}
	close(fd);
	printf("printing linked list\n");
	pall(&h, 0);
}
