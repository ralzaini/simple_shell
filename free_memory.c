#include "shell.h"

/**
 * free_memory - a function to free allocated memory
 * @str: array of arguments
 *
 * Return: nothing
*/

void free_memory(char **str)
{
	int i = 0;

	if (!str)
	{
		return;
	}
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

/**
 * _printerror - a function to print error.
 * @name: passed variable.
 * @input: passed variable.
 * @index: index passed to the variable.
 *
 * Return: nothing
*/

void _printerror(char *name, char *input, int index)
{
	char *idx, message[] = ": not found\n";

	idx = _itoa(index);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, input, _strlen(input));
	write(STDERR_FILENO, message, _strlen(message));

	free(idx);
}
