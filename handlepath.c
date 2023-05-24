#include "shell.h"

/**
 * _strjoin - join strings
 *
 * @s1: first str
 * @s2: second str
 * Return: s
 */

char *_strjoin(char *s1, char *s2)
{
	int i = 0, j = 0;
	char *s0 = malloc(_strlen(s1) + _strlen(s2) + 2);

	while (s1[i])
	{
		s0[i] = s1[i];
		i++;
	}
	s0[i] = '/';
	s0[i + 1] = '\0';
	while (s2[j])
	{
		s0[i + j + 1] = s2[j];
		j++;
	}
	s0[i + j + 1] = '\0';

	return (s0);
}
/**
 * handlepath - handle path
 *
 * @path: the environment path
 * @cmd: the command
 *
 * Return: path or NULL
 */

char *handlepath(char *path, char *cmd)
{
	char *dir;
	char *apath;
	char *p;

	if (cmd[0] == '/')
	{
		free(path);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		return (NULL);
	}

	p = _strdup(path);
	free(path);
	dir = strtok(p, ":");
	while (dir != NULL)
	{
		apath = _strjoin(dir, cmd);
		if (access(apath, X_OK) == 0)
		{
			free(p);
			return (apath);
		}
		free(apath);
		dir = strtok(NULL, ":");
	}
	free(p);
	return (NULL);
}
