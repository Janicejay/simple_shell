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
		if (str_cmp(command[0], "cd") == 0)
		{
			cd_builtin(argv, linecount, command);
			free(args);
			free_mem(command);
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

/**
 * cd_builtin - function that handles the cd builtin command
 * @argv: argument variables; contains program name
 * @linecount: counts the number of times the shell runs
 * @command: contains command input
 * Return: void
 */
void cd_builtin(char *argv[], int linecount, char **command)
{
	char c_w_d[BUFFER_SIZE], message[BUFFER_SIZE] = "can't cd to ";
	char *directory, *previous_directory = getenv("OLDPWD");
	char *home = getenv("HOME");
	int chdir_status;

	if (previous_directory == NULL)
	{
		perror("getenv: OLDPWD does not exist");
		return;
	}
	if (home == NULL)
	{
		perror("getenv: HOME does not exist");
		return;
	}

	if (command[1] == NULL || (str_cmp(command[1], "~") == 0))
		directory = home;
	else if (str_cmp(command[1], "-") == 0)
	{
		directory = previous_directory;
		print_stdout(directory);
		print_stdout("\n");
	}
	else
		directory = command[1];

	chdir_status = chdir(directory);
	if (chdir_status != 0)
	{
		strcat(message, directory);
		error_msg(argv, linecount, command[0], message, 0);
		return;
	}

	setenv("OLDPWD", getenv("PWD"), 1);
	if (getcwd(c_w_d, sizeof(c_w_d)) != NULL)
		setenv("PWD", c_w_d, 1);
	else
		perror("getcwd is NULL");
}
