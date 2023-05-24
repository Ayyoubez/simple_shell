#include "shell.h"

/**
 * freecmd - free commands
 * @cmd: array of strs
 */
void freecmd(char **cmd)
{
	int i = 0;

	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
}
/**
*builtin - built in function
*@cmd: commandi
*Return: 1 or 0
*/

int builtin(char **cmd)
{
	int i = 0;

	if (_strcmp(cmd[0], "exit") == 0)
	{
		freecmd(cmd);
		_exit(0);
	}
	if (_strcmp(cmd[0], "env") == 0)
	{
		while (environ[i])
		{
			write(1, environ[i], _strlen(environ[i]));
			write(1, "\n", 1);
			i++;
		}
		return (0);
	}
	return (1);
}
