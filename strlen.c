#include "shell.h"

/**
 * _strlen - string length
 * @s: string
 * Return: length
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}
