#include "shell.h"

int _exec(char **command, char **argv, int index)
{
	pid_t child;
	int status;
	char *full_input;

	full_input = _getpath(command[0]);
	if (!full_input)
	{
		_printerror(argv[0], command[0], index);
		free_memory(command);
		return(127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(full_input, command, environ) == -1)
		{
			free(full_input);
			full_input = NULL;
			free_memory(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_memory(command);
		free(full_input);
		full_input = NULL;
	}
	return (WEXITSTATUS(status));
}
