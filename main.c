#include "shell.h"
/**
*main - main program
*@ac: num of args
*@argv: array of args
*@env: env variable array
*Return: always (0)
*/

int main(int ac, char **argv, char **env)
{
	if (ac == 1)
		prompt(argv, env);
	return (0);
}
