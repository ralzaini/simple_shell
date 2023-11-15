#include "shell.h"

/**
 * get_line - get the command line
 *
 * Return: number of read characters or -1
*/

char *get_line(void)
{
	char *command_line = NULL;
	size_t len = 0;
	ssize_t input;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	input = getline(&command_line, &len, stdin);

	if (input == -1)
	{
		free(command_line);
		return (NULL);
	}
	return (command_line);
}
