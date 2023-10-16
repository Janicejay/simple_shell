#include "shell.h"

static ssize_t buffer_idx;
static ssize_t bytesReadInBuffer;
static char buffer[BUFFER_SIZE];

/**
 * custom_getline - Read a line from a file descriptor
 * @line_ptr: Pointer to a pointer to the line buffer
 * @n: Pointer to the buffer size
 * @fd: File descriptor to read from
 *
 * Return: The number of bytes read, or -1 on failure.
 */
ssize_t custom_getline(char **line_ptr, size_t *n, int fd)
{
	size_t bytesRead = 0;
	char ch;

	if (line_ptr == NULL || n == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	if (*line_ptr == NULL || *n == 0)
	{
		if (initialize_buffer(line_ptr, n) == -1)
			return (-1);
	}

	while (1)
	{
		if (buffer_idx >= bytesReadInBuffer)
		{
			if (fill_buffer(fd) == -1)
				return (-1);
			if (bytesReadInBuffer == 0)
			{
				if (bytesRead == 0)
					return (-1);
				break;
			}
		}
		ch = buffer[buffer_idx++];
		if (bytesRead >= *n - 1)
		{
			if (reallocate_buffer(line_ptr, n) == -1)
				return (-1);
		}
		(*line_ptr)[bytesRead] = ch;
		bytesRead++;
		if (ch == '\n')
			break;
	}
	(*line_ptr)[bytesRead] = '\0';
	return (bytesRead);
}

/**
 * initialize_buffer - Initialize the line buffer with an initial size
 * @line_ptr: Pointer to a pointer to the line buffer
 * @n: Pointer to the buffer size
 *
 * Return: 0 on success, -1 on memory allocation error.
 */
int initialize_buffer(char **line_ptr, size_t *n)
{
	*n = 128;
	*line_ptr = (char *)malloc(*n);
	if (*line_ptr == NULL)
	{
		return (-1);
	}
	return (0);
}

/**
 * fill_buffer - Fill the buffer with data from a file descriptor
 * @fd: File descriptor to read from
 *
 * Return: The number of bytes read, or -1 on failure.
 */
ssize_t fill_buffer(int fd)
{
	ssize_t bytesRead = read(fd, buffer, BUFFER_SIZE);

	if (bytesRead == -1 && errno == EINTR)
	{
		return (fill_buffer(fd));
	}
	bytesReadInBuffer = bytesRead;
	buffer_idx = 0;
	return (bytesReadInBuffer);
}

/**
 * reallocate_buffer - Expand the line buffer to accommodate more data
 * @line_ptr: Pointer to a pointer to the line buffer
 * @n: Pointer to the buffer size
 *
 * Return: 0 on success, -1 on memory allocation error.
 */
ssize_t reallocate_buffer(char **line_ptr, size_t *n)
{
	size_t new_size = (*n) * 2;
	char *new_ptr = (char *)shell_realloc(*line_ptr, new_size);

	if (new_ptr == NULL)
	{
		return (-1);
	}
	*line_ptr = new_ptr;
	*n = new_size;
	return (0);
}
