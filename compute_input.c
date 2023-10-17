#include "shell.h"

/**
 * compute_input - function that proccesses input
 * @interactive: determines the mode of the custom shell
 * @input_fd: stdin or file
 * @argc: argument count
 * @argv: argument variables
 * @linecount: line count
 * Return: void
 */
void compute_input(int interactive,
		int input_fd, int argc, char *argv[], int linecount)
{
	char *input = NULL;
	char **args = NULL;
	char **commands = NULL;
	int i = 0, status;

	(void)argc;
	if (interactive)
	{
		write(STDOUT_FILENO, "$garri$ ", _strlen("$garri$ "));
		fflush(stdout);
	}

	input = get_input(input_fd);
	status = builtin_commands(input, argv, linecount);
	if (status == 0)
		return;
	args = split_input(input);
	if (args == NULL && args[0] == NULL)
	{
		free(input);
		free_mem(args);
		return;
	}
	free(input);

	while (args[i] != NULL)
	{
		commands = split_command(args[i]);
		execute_command(commands, interactive, argv, linecount);
		free_mem(commands);
		i++;
	}
	free_mem(args);
}
