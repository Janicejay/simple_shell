#include "shell.h"

/**
 * execute_command - function that executes commands
 * @args: double pointer to tokenized string
 * @interactive: determines the mode
 * @argv: command line argument
 * @linecount: number of times the shell ran
 * Return: EXIT STATUS
 */
int execute_command(char **args, int interactive, char *argv[], int linecount)
{
	int status;
	pid_t pid;
	char *str = args[0];

	(void)interactive;

	if (args == NULL || args[0] == NULL)
		return (-1);

	if (str_chr(args[0], '/') != 0)
		str = concatenatePath(str);
	if (access(str, F_OK) == 0 && access(str, X_OK) == 0)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			return (1);
		}
		if (pid == 0)
		{
			execve(str, args, environ);
			perror("./hsh");
			exit(EXIT_FAILURE);
		} else
			wait(&status);
		if (str_chr(args[0], '/') != 0)
			free(str);
	} else
	{
		error_msg(argv, linecount, args[0], "not found", NULL);
		if (str_chr(args[0], '/') != 0)
			free(str);
		return (1);
	} return (0);
}
