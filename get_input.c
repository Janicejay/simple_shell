#include "shell.h"

/**
 * get_input - gets input
 * @input_fd: determines whether to read from stdin or file
 * Return: pointer to input
 */
char *get_input(int input_fd)
{
	char *input = NULL;
	size_t input_length = 0;
	ssize_t bytes_read;

	bytes_read = custom_getline(&input, &input_length, input_fd);


	if (bytes_read == -1 && input_length > 0)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}

	if (bytes_read == -1)
	{
		free(input);
		perror("getline");
		exit(EXIT_FAILURE);
	}
	if (bytes_read > 0 && input[bytes_read - 1] == '\n')
	{
		input[bytes_read - 1] = '\0';
		return (input);
	}

	return (NULL);
}
