#include "shell.h"

/**
 * _strdup -  returns a pointer to a newly allocated space in memory.
 * @str: string to copy.
 * Return: Always 0.
 */

char *_strdup(char *str)
{
	int i, j;
	char *n;

	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
		;

	n = malloc(i * sizeof(*str) + 1);
	if (n == 0)
	{
		return (NULL);
	}
	for (j = 0; j < i; j++)
	{
		n[j] = str[j];
	}
	n[j] = '\0';
	return (n);
}

/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}

	return (0);
}

/**
*_strlen - returns the length of a string..
*@s: value to be evaluate.
*Return: not.
*/

int _strlen(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

/**
 *_strcpy - update value.
 *@dest: value to be evaluate.
 *@src: value to be evaluate.
 *Return: not.
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
