#include "shell.h"

/**
 * _strlen - function that gets length of string
 * @format: input string
 * Return: returns length of string
 */
int _strlen(const char *format)
{
	int i = 0;

	while (*format)
	{
		i++;
		format++;
	}

	return (i);
}

/**
 * putchar_stdout - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int putchar_stdout(char c)
{
	return (write(1, &c, 1));
}

/**
 * free_mem - functions that frees double pointers
 * @args: double pointer to be freed
 * Return: void
 */
void free_mem(char **args)
{
	int i;

	if (args == NULL)
		return;
	for (i = 0; args[i]; i++)
	{
		if (args[i] != NULL)
		{
			free(args[i]);
		}
	}
	if (args != NULL)
		free(args);
}


/**
 * _strdup -   returns a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter.
 *
 * @str: string input
 * Return: a pointer to a newly allocated space in memory
 */
char *_strdup(char *str)
{
	int i;
	char *ptr;
	char *ptr_offset;

	if (str == NULL)
	{
		return (NULL);
	}

	i = _strlen(str);

	ptr = (char *) malloc((i + 1) * sizeof(char));

	if (ptr == NULL)
	{
		return (NULL);
	}

	ptr_offset = ptr;
	while (*str)
	{
		*ptr_offset = *str;
		ptr_offset++;
		str++;
	}
	*ptr_offset = '\0';

	return (ptr);

}

/**
 * str_cat - concatenates two strings.
 *
 * @dest: pointing to destination file
 * @src: source
 *
 * Return: char
 */
char *str_cat(char *dest, char *src)
{
	char *ptr;

	ptr = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (ptr);
}
