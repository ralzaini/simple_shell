#include "shell.h"

/**
 * builtin_checker - a function passed to checkthe entered command
 *
 * @command: passed command to the function.
 *
 * Return: 1 is builtin or 0 if not
*/

int builtin_checker(char *command)
{
	char *built_ins[] = {
		"cd", "env",
		"exit", "setenv", NULL
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

/**
 * handler - a function to handel the differenct args.
 *
 * @command: passed command to the function.
 * @argv: argument passed to the function.
 * @status: status passed to the function.
 * @index: index passed to the function.
 * @ac: passed argument to the function.
 *
 * Return: nothing
 */

void handler(char **command, char **argv, int *status, int index, int ac)
{
	(void) ac;

	if (_strcmp(command[0], "exit") == 0)
		shell_exit(command, argv, status, index);
	else if (_strcmp(command[0], "env") == 0)
		env_print(command, status);
	else if (_strcmp(command[0], "cd") == 0)
		change_directory(command[1], status);
}

/**
 * shell_exit - a function to handel the differenct args.
 *
 * @command: passed command to the function.
 * @argv: argument passed to the function.
 * @status: status passed to the function.
 * @index: index passed to the function.
 *
 * Return: nothin
 */

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

/**
 * env_print - a function to print env
 *
 * @command: passed command
 * @status: passed status
 *
 * return: nothing
 */

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

/**
 * change_directory - a function to change the directory
 *
 * @directory: passed command
 * @status: passed status
 *
 * return: nothing
 */

void change_directory(char *directory, int *status)
{
	char *error_message = "OLDPWD environment variable not set.\n";
	char *home_dir = getenv("HOME"), *current_dir = getcwd(NULL, 0);

	if (directory == NULL)
	{
		if (home_dir != NULL)
		{
			if (chdir(home_dir) != 0)
			{
				perror("cd");
				(*status) = 1;
			}
			else
				(*status) = 0;
		}
		else
		{
			write(STDERR_FILENO, error_message, strlen(error_message));
			(*status) = 1;
		}
	}
	else
	{
		if (chdir(directory) != 0)
		{
			perror("cd");
			(*status) = 1;
		}
		else
		{
			if (current_dir != NULL)
			{
				setenv("PWD", current_dir, 1);
				setenv("OLDPWD", current_dir, 1);
				free(current_dir);
			}
			(*status) = 0;
		}
	}
	free(directory);
}
