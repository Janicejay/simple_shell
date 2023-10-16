#include "shell.h"

/**
 * split_command - function that further tokenizes input
 * @command: pointer to args[i]
 * Return: double pointer to tokenized strings
 */
char **split_command(char *command)
{
	char **args = NULL;
	char *token = NULL;
	int i = 0;
	char *command_cpy;

	if (command == NULL)
	{
		perror("strdup: split_command");
		exit(EXIT_FAILURE);
	}
	command_cpy = _strdup(command);

	if (command_cpy == NULL)
	{
		perror("split_command");
		exit(EXIT_FAILURE);
	}

	args = malloc(1000 * sizeof(char *));

	if (args == NULL)
	{
		perror("malloc: split_command");
		exit(EXIT_FAILURE);
	}
	token = strtok(command_cpy, " \n\t\r");
	while (token != NULL)
	{
		args[i] = _strdup(token);
		if (args[i] == NULL)
		{
			perror("strdup: token: split_command");
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, " \n\t\r");
	}
	args[i] = NULL;
	free(command_cpy);
	return (args);
}
