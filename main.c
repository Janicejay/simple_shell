#include "shell.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument variable
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	int input_fd = STDIN_FILENO;
	int interactive = isatty(STDIN_FILENO);
	int linecount = 1;

	if (argc > 1)
	{
		interactive = 0;
		input_fd = open(argv[1], O_RDONLY);
		if (input_fd == -1)
		{
			if (errno == EACCES)
				perror("File Permission denied");
			else
				perror("File not found");
			exit(EXIT_FAILURE);
		}
	}

	while (true)
	{
		compute_input(interactive, input_fd, argc, argv, linecount);
		if (input_fd != 0)
		{
			close(input_fd);
			break;
		}

		linecount++;
	}


	return (0);
}
