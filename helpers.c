#include "shell.h"

/**
 * _itoa - convert string to integer
 * @index: integer
 *
 * Return: converted integer
 */

char *_itoa(int index)
{
	int i = 0;
	char input[20];

	if (index == 0)
		input[i++] = '0';
	else
	{
		while (index > 0)
		{
			input[i++] = (index % 10) + '0';
			index /= 10;
		}
	}
	input[i] = '\0';
	rev_string(input);
	return (_strdup(input));
}

/**
 *rev_string - update value.
 *@str: value to be evaluate.
 *Return: not.
 */

void rev_string(char *str)
{
	int i = 0, j, k;
	char t;

	while (str[i] != '\0')
	{
		i++;
	}

	k = i;
	for (i--, j = 0; j < k / 2; i--, j++)
	{
		t = str[j];
		str[j] = str[i];
		str[i] = t;
	}

}

/**
 * print_errorno - a function to print errors.
 *
 * @command: the passed command
 * @idx: the passed index
 * @message: the passed message
 * @arg: the passed argument
 *
 * Return: nothing
*/

void print_errorno(char *command, char *idx, char *message, char *arg)
{
	 write(STDERR_FILENO, command, _strlen(command));
	 write(STDERR_FILENO, ": ", 2);
	 write(STDERR_FILENO, idx, _strlen(idx));
	 write(STDERR_FILENO, message, _strlen(message));
	 write(STDERR_FILENO, arg, _strlen(arg));
	 write(STDERR_FILENO, "\n", 1);
}

/**
 * pos_number - a function to check if the input is a positive number
 * @str: string to check
 *
 * Return: 1 if number, 0 if not
*/

int pos_number(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		return (0);
		i++;
	}
	return (1);
}

/**
 * _atoi - convert string to integer
 * @str: string
 *
 * Return: converted integer
 */

int _atoi(char *str)
{
	int i = 0, number = 0;

	while (str[i])
	{
		number *= 10;
		number += (str[i] - '0');
		i++;
	}
	return (number);
}
