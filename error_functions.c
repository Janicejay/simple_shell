#include "shell.h"

/**
 * error_msg - prints error message in non-interactive mode
 * @argv: contains program name
 * @linecount: line count
 * @str: command name
 * @message: error message
 * @command: command name
 * Return: void
 */
void error_msg(char *argv[], int linecount,
		char *str, char *message, char *command)
{
	print_stderr(argv[0]);
	print_stderr(": ");
	print_number_stderr(linecount);
	print_stderr(": ");
	print_stderr(str);
	print_stderr(": ");
	print_stderr(message);
	if (command != NULL)
	{
		print_stderr(": ");
		print_stderr(command);
	}
	print_stderr("\n");
}



/**
 * putchar_stderr - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int putchar_stderr(char c)
{
	return (write(2, &c, 1));
}

/**
 * print_number_stderr - prints number to standard error
 * @number: integer to be printed
 * Return: void
 */
void print_number_stderr(int number)
{
	int index = 0;
	char buffer[100];

	if (number == 0)
	{
		putchar_stderr('0');
		return;
	}

	if (number < 0)
	{
		putchar_stderr('-');
		number = -number;
	}

	while (number > 0)
	{
		buffer[index++] = (char)((number % 10) + '0');
		number /= 10;
	}

	while (index > 0)
	{
		putchar_stderr(buffer[--index]);
	}
}

/**
 * print_stderr - prints a string
 * @str: input string
 * Return: void
 */
void print_stderr(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	write(STDERR_FILENO, str, len);
}
