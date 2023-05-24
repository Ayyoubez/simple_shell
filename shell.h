#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define NUM_CMD 10

extern char **environ;
void builtin(char **cmd);
int _strlen(char *s);
void  prompt(char **av, char **en);
char *handlepath(char *path, char *cmd);
int _strcmp(const char *s1, const char *s2);
char *_getenv(const char *name);
char *_strdup(char *str);










#endif
