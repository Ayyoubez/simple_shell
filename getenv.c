#include "shell.h"

/**
 * _getenv - get environment variable
 * @name: variable name
 * Return: value
 */


char *_getenv(const char *name)
{
	unsigned int i = 0;
	char *s;
	char *cpy;

	while (environ[i])
	{
		cpy = _strdup(environ[i]);
		s = strtok(cpy, "=");
		if (_strcmp(s, name) == 0)
		{
			s = strtok(NULL, "=");
			return (s);
		}
		i++;
	}
	return (NULL);
}
