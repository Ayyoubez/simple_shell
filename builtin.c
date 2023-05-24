#include "shell.h"
/**
*builtin - built in function
*@cmd: command
*/

void builtin(char *cmd)
{
	int i = 0;

	if (_strcmp(cmd, "exit") == 0)
		_exit(1);
	if (_strcmp(cmd, "env") == 0)
	{
		while (environ[i])
		{
			write(1, environ[i], _strlen(environ[i]));
				write(1, "\n", 1);
			i++;
		}
	}
}
