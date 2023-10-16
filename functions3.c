#include "shell.h"

/**
 * atoi_custom - converts string to integer
 * @str: string to be converted
 * Return: integer value
 */
int atoi_custom(char *str)
{
	long int number = 0;
	long int sign = 1;
	int i = 0;

	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			return (-1);
		i++;
	}

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}

	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}

	if (*str != '\0')
		return (EXIT_FAILURE);
	return (sign * number);
}

/**
 * strtok_custom - tokenizes a string
 * @str: string to be tokenized
 * @delimeter: The delimeter
 * Return: pointer to string
 */
char *strtok_custom(char *str, char *delimeter)
{
	char *temp_token;
	static char *token;

	if (str != NULL)
		token = str;
	else if (token == NULL)
		return (NULL);

	while (*token != '\0' && str_chr(delimeter, *token) != 1)
		token++;

	if (*token == '\0')
		return (NULL);

	temp_token = token;

	while (*token != '\0' && str_chr(delimeter, *token) == 1)
		token++;

	if (*token != '\0')
	{
		*token = '\0';
		token++;
	}

	return (temp_token);
}

/**
 * print_stdout - prints a string
 * @str: input string
 * Return: void
 */
void print_stdout(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	write(STDOUT_FILENO, str, len);
}


