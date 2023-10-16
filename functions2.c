#include "shell.h"

/**
 * str_cmp - function that compares two strings.
 *
 * @s1: first string to be compared.
 * @s2: second string to be compared.
 *
 * Return: int
 */
int str_cmp(char *s1, char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (0);
	else if (s1 == NULL || s2 == NULL)
		return (1);

	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (1);
		}
		s1++;
		s2++;
	}
	return (*s1 != *s2);
}

/**
 * str_cpy - copy the string pointed to by src to buffer pointed to by dest
 *
 * @dest: pointer to the buffer destination
 * @src: pointer to the source string
 *
 * Return: pointer to dest
 */
char *str_cpy(char *dest, char *src)
{
	char *pointer;

	pointer = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (pointer);
}

/**
 * concatenatePath - function that concatenates a path
 * @filename: name of file to be concatenated
 * Return: pointer to concatenated string
 */
char *concatenatePath(char *filename)
{
	char *str;

	str = (char *)malloc(_strlen("/bin/") + _strlen(filename) + 1);

	if (str != NULL)
	{
		str_cpy(str, "/bin/");
		str_cat(str, filename);
		return (str);
	}
	else
	{
		perror("Malloc failed: concatenatePath");
		exit(EXIT_FAILURE);
	}

	free(str);
	return (NULL);

}

/**
 * _strncmp - compares the first n bytes of 2 strings
 * @s1: string input
 * @s2: string input
 * @n: number of bytes to compare
 * Return: 0 if successful
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	int flag;

	while (*s1 && *s2 && n > 0)
	{
		if (*s1 != *s2)
		{
			flag = 1;
			break;
		}
		s1++;
		s2++;
		n--;
	}
	if (flag == 0 || n == 0)
		return (0);
	else
		return (1);
}

/**
 * str_chr - searches for first occurrence of a specific char
 * @str: string to search
 * @character: character to search for
 * Return: 0 if char exists
 */
int str_chr(char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == character)
			return (0);

		str++;
	}

	return (1);
}
