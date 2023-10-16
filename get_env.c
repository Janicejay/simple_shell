#include "shell.h"

/**
 * get_env - function that prints the curent environment
 * Return: void
 */
void get_env(void)
{
	char **env_p = environ;

	while (*env_p)
	{
		print_stdout(*env_p);
		putchar_stdout('\n');
		env_p++;
	}
}
