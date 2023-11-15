#include "shell.h"

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
