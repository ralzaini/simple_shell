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

/**
 * _getenv - get env value.
 * @variable: variable of the env function.
 *
 * Return: pointer to the value or NULL.
*/

char *_getenv(char *variable)
{
	char *temp, *key, *environment, *value;
	int index = 0;

	while (environ[index])
	{
		temp = _strdup(environ[index]);
		key = strtok(temp, ENVDELIM);
		if (_strcmp(key, variable) == 0)
		{
			value = strtok(NULL, ENVDELIM);
			environment = _strdup(value);
			free(temp);
			return (environment);
		}
		free(temp);
		temp = NULL;
		index++;
	}
	return (NULL);
}

/**
 * _getpath - get the right path.
 *
 * @filename: the path passed to the shell.
 *
 * Return: path or NULL
*/

char *_getpath(char *filename)
{
	char *search_path, *full_path, *current_directory;
	int index = 0;
	struct stat file_info;

	while (filename[index])
	{
		if (filename[index] == '/')
		{
			if (stat(filename, &file_info) == 0)
				return (_strdup(filename));
			return (NULL);
		}
		index++;
	}
	search_path = _getenv("PATH");
	if (!search_path)
		return (NULL);
	current_directory = strtok(search_path, PATHDEL);
	while (current_directory)
	{
		full_path = malloc(_strlen(current_directory) + _strlen(filename) + 2);
		if (full_path)
		{
			_strcpy(full_path, current_directory);
			_strcat(full_path, "/");
			_strcat(full_path, filename);
			if (stat(full_path, &file_info) == 0)
			{
				free(search_path);
				return (full_path);
			}
			free(full_path), full_path = NULL;
			current_directory = strtok(NULL, PATHDEL);
		}
	}
	free(search_path);
	return (NULL);
}
