#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* Global environemnt */
extern char **environ;

/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */

typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/* Main Helpers */
char **split_line(char *line);
int isfiledefault(const char *path);
void _exec(char **args);

/* String functions */
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/* Built-ins */
int env_builtin(char **args, char __attribute__((__unused__)) **front);


/* Built-in Helpers */
char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);

#endif /* SHELL_H */
