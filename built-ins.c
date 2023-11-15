#include "shell.h"

int builtin_checker(char *command)
{
	char *built_ins[] = {
		"cd", "env", "setenv", "exit", NULL
	};
	int i = 0;

	while (built_ins[i])
	{
		if (_strcmp(command, built_ins[i]) == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void builtin_handler(char **command, char **argv, int *status, int index)
{
	if (_strcmp(command[0], "exit") == 0)
		shell_exit(command, argv, status, index);
	else if (_strcmp(command[0], "env") == 0)
		env_print(command, status);
}

void shell_exit(char **command, char **argv, int *status, int index)
{
	int value = (*status);
	char message[] = ": exit: Illegal number: ";
	char *idx;

	if (command[1])
	{
		if (pos_number(command[1]))
		{
			value = _atoi(command[1]);
		}
		else
		{
			idx = _itoa(index);
			print_errorno(argv[0], idx, message, command[1]);
			free(idx);
			free_memory(command);
			(*status) = 2;
			return;
		}
	}

	free_memory(command);
	exit(value);
}

void env_print(char **command, int *status)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	free_memory(command);
	(*status) = 0;
}
