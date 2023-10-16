#include "shell.h"

/**
 * shell_realloc - function that reallocates memory
 * @ptr: pointer
 * @size: size for reallocated memory
 * Return: pointer
 */
void *shell_realloc(void *ptr, size_t size)
{
	void *new_ptr;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(size);

	if (new_ptr == NULL)
	{
		return (NULL);
	}

	if (ptr != NULL)
	{
		shell_memcpy(new_ptr, ptr, size);
		free(ptr);
	}

	return (new_ptr);
}

/**
 * shell_memcpy - function that copies memory area.
 *
 * @dest: destination pointer
 * @src: memory area to be copied
 * @n: copies n bytes
 *
 * Return: a pointer to dest
 */
char *shell_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	if (*src != '\0')
	{
		for (i = 0; i < n; i++)
		{
			dest[i] = src[i];
		}
	}
	return (dest);
}
