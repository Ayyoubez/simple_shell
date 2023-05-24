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
*@cmd: command
*/

void builtin(char **cmd)
{
	int i = 0;

	if (_strcmp(cmd[0], "exit") == 0)
	{
		freecmd(cmd);
		_exit(1);
	}
	if (_strcmp(cmd[0], "env") == 0)
	{
		while (environ[i])
		{
			write(1, environ[i], _strlen(environ[i]));
			write(1, "\n", 1);
			i++;
		}
	}
}
