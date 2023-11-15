#include "shell.h"

char *_itoa(int j)
{
	int i = 0;
	char input[20];

	if (j == 0)
		input[i++] = '0';
	else
	{
		while (j > 0)
		{
			input[i++] = (j % 10) + '0';
			j /= 10;
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

void print_errorno(char *command, char *idx, char *message, char *arg)
{
	 write(STDERR_FILENO, command, _strlen(command));
	 write(STDERR_FILENO, ": ", 2);
	 write(STDERR_FILENO, idx, _strlen(idx));
	 write(STDERR_FILENO, message, _strlen(message));
	 write(STDERR_FILENO, arg, _strlen(arg));
	 write(STDERR_FILENO, "\n", 1);
}

int pos_number(char *str)
{
	int i = 0;

	if (!str)
		return(0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		return (0);
		i++;
	}
	return (1);
}

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
