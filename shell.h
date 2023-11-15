#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"
#define ENVDELIM "=\n"
#define PATHDEL ":"

extern char **environ;

/* Get Line (get_line.c) */
char *get_line(void);
int _exec(char **command, char **argv, int index);
char *_getenv(char *var);
char *_getpath(char *input);

/*Helpers (helpers.c) */
char *_itoa(int j);
void rev_string(char *str);
void print_errorno(char *command, char *idx, char *message, char *arg);
int pos_number(char *str);
int _atoi(char *str);

/* free memory (free_memory.c) */
void free_memory(char **str);
void _printerror(char *name, char *input, int index);

/* String Functions (strings.h) */
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

/* Tokenizer (tokrnizer.c) */
char **_tokenizers(char *line);

/* BUILTIN_CHECKER (built-ins.c & built-ins2.c) */
int builtin_checker(char *command);
void handler(char **command, char **argv, int *status, int index, int ac);
void shell_exit(char **command, char **argv, int *status, int index);
void env_print(char **command, int *status);
void change_directory(char *command, int *status);

#endif
