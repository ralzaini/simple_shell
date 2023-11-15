#include "shell.h"

void free_memory(char **str)
{
	int i;

	if (!str)
	{
		return;
	}
	for (i = 0; str[i]; i++)
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}

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
