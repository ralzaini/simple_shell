#include "shell.h"

/**
 * _tokenizers - parse the string to different lines.
 *
 * @command_line: the line to parse.
 *
 * Return: return table of commands
*/

char **_tokenizers(char *command_line)
{
	char *token_line = NULL, *tmp = NULL, **command = NULL;
	int count = 0, i = 0;

	if (!command_line)
		return (NULL);

	tmp = _strdup(command_line);
	token_line = strtok(tmp, DELIM);
	if (token_line == NULL)
	{
		free(command_line), command_line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token_line)
	{
		count++;
		token_line = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		free(command_line), command_line = NULL;
		return (NULL);
	}
	token_line = strtok(command_line, DELIM);
	while (token_line)
	{
		command[i] = _strdup(token_line);
		token_line = strtok(NULL, DELIM);
		i++;
	}
	free(command_line), command_line = NULL;
	command[i] = NULL;
	return (command);
}
