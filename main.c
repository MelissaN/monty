#include "monty.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd, i, ispush = 0;
	ssize_t n_read, n_wrote;
	char *buffer;
	char *token;

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
// 	n_wrote = write(STDOUT_FILENO, buffer, n_read);
// 	if (n_wrote == -1)
// 	{
// 		free(buffer);
// 		close(fd);
// 		exit(EXIT_FAILURE);
// 	}
//

	token = strtok(buffer, "\n\t\a\r ;:");
	while (token != NULL)
	{

		if (ispush == 1)
		{
			get_op_func(
		}
		if (strcmp(token, "push") == 0)
		{
			printf("eeeeeee");
			ispush = 1;
			token = strtok(NULL, "\n\t\a\r ;:");
			i++;
			continue;
		}









		token = strtok(NULL, "\n\t\a\r ;:");
		i++;
	}
	close(fd);
}
