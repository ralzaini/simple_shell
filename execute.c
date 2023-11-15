#include "shell.h"

/**
 * _exec - a function to execute commands
 * @command: commands array passed
 * @argv: arguments array passed
 * @index: index of the line passed
 *
 * Return: status
*/

int _exec(char **command, char **argv, int index)
{
	pid_t child_pid;
	int child_status;
	char *full_input;

	full_input = _getpath(command[0]);
	if (!full_input)
	{
		_printerror(argv[0], command[0], index);
		free_memory(command);
		return (127);
	}
	child_pid = fork();
	if (child_pid == 0)
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
		waitpid(child_pid, &child_status, 0);
		free_memory(command);
		free(full_input);
		full_input = NULL;
	}
	return (WEXITSTATUS(child_status));
}
