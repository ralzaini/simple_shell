#include "shell.h"

/**
 * main -  entry point of the program.
 *
 * @ac: command line arguments.
 * @argv: command line argument values.
 *
 * Return: nothing
*/

int main(int ac, char **argv)
{
	char *input_line = NULL, **cmd = NULL;
	int status = 0, index = 0;
	(void) ac;

	do {
		input_line = get_line();
		if (input_line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (status);
		}
		index++;
		cmd = _tokenizers(input_line);
		if (!cmd)
			continue;

		if (builtin_checker(cmd[0]))
			handler(cmd, argv, &status, index, ac);
		else
			status = _exec(cmd, argv, index);
	} while (1);
}
