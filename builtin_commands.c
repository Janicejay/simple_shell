#include "shell.h"
/**
 * builtin_commands - executes builtin commands
 * @args: pointer to string
 * @argv: contains program name
 * @linecount: shell count
 * Return: 0 if command successfully ran, -1 if otherwise
 */
int builtin_commands(char *args, char *argv[], int linecount)
{

	if (args != NULL)
	{
		char **command = split_command(args);

		if (str_cmp(command[0], "exit") == 0)
		{
			exit_builtin(args, command, argv, linecount);
			return (0);
		}
		else if (str_cmp(command[0], "env") == 0)
		{
			free(args);
			free_mem(command);
			get_env();
			return (0);
		}
		free_mem(command);
	}
	return (-1);
}

/**
 * exit_builtin - exit implementation
 * @args: string input
 * @command: array of strings
 * @argv: contains program name
 * @linecount: tracks loop
 * Return void
 */
void exit_builtin(char *args, char **command, char *argv[], int linecount)
{
	long int status;

	if (command[1] != NULL)
	{
		status = atoi_custom(command[1]);
		if (status < 0 || status > INT_MAX)
		{
			error_msg(argv, linecount, command[0], "Illegal number", command[1]);
			free(args);
			free_mem(command);
			return;
		}
		free(args);
		free_mem(command);
		exit(status);
	}
	else
	{
		free(args);
		free_mem(command);
		exit(EXIT_SUCCESS);
	}
}
