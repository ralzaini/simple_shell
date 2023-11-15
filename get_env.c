#include "shell.h"

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
