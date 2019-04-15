#ifndef _SHELL_H_
#define _SHELL_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
extern char **environ;
typedef struct built {
	char *name;
	int (*fun) (void);
} built_s;
int xexit(void);
int xenv(void);
int exc_built(char **args);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2, unsigned int n);
int execute(char **path, char **args);
char **_strcut(char *line, const char *separator, char **arg_0);
int _strcmp(char *s1, char *s2);
int get_env(char *var, char **own_envir);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
#endif
