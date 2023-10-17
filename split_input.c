#include "shell.h"

/**
 * split_input - tokenize a string
 * @input: pointer to string
 * Return: pointer to tokenized stings
 */
char **split_input(char *input)
{
	char **args = NULL;
	int i = 0;
	char *token = NULL;
	char *input_cpy;

	if (input == NULL)
	{
		perror("strdup: split_input");
		exit(EXIT_FAILURE);
	}
	input_cpy = _strdup(input);
	if (input_cpy == NULL)
	{
		perror("split_line");
		exit(EXIT_FAILURE);
	}

	args = malloc(1000 * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc: split_line");
		exit(EXIT_FAILURE);
	}
	token = strtok(input_cpy, ";");
	while (token != NULL)
	{
		args[i] = _strdup(token);
		if (args[i] == NULL)
		{
			perror("strdup: split_line");
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, ";");
	}
	args[i] = NULL;
	free(input_cpy);
	return (args);
}
