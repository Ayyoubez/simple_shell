#include "shell.h"
/**
*handleinput - handle input
*@str: string
*@argv: array of strings
*/

void handleinput(char *str, char *argv[])
{
	int i = 0, j = 0;
	char *token;

	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	if (str == NULL)
		return;
	token = strtok(str, " ");
	while (token != NULL)
	{
		argv[j] = token;
		j++;
		token = strtok(NULL, " ");
	}
	argv[j] = NULL;
}
/**
*runprogram - running commands
*@argv: array of args
*@en: envirenment array
*/

void runprogram(char **argv, char **en)
{
	pid_t child;

	child = fork();
	if (child == -1)
	{
		free(argv[0]);
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		if (execve(argv[0], argv, en) == -1)
			perror("Erroe during execution..");
	}
	else
	{
		wait(NULL);
	}
}
/**
*prompt - prompt in terminal
*@av: argv by main
*@en: en by main
*/

void prompt(char **av, char **en)
{
	char *str = NULL;
	ssize_t n_char;
	size_t n = 0;
	char *argv[NUM_CMD];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "Cisfun$ ", 8);
		n_char = getline(&str, &n, stdin);
		if (n_char == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		handleinput(str, argv);
		if (!argv[0])
			continue;
		builtin(argv);
		argv[0] = handlepath(_getenv("PATH"), argv[0]);
		if (argv[0] == NULL)
		{
			write(1, av[0], _strlen(av[0]));
			write(1, ":No such file or directory\n", 28);
			continue;
		}
		runprogram(argv, en);
	}
}
