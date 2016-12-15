#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
/* delete when functions are built */
#include <string.h>
/* end delete when functions are built */

#define BUFSIZE 1024
extern char **environ;

/* In builtins.h */
void _env(void);
void _cd(void);
void _alias(void);
void history(void);
void help(void);

/* in environment.c */
/**
  * struct environ_path - linked list from PATH
  * @path: path in the format /usr/bin
  * @len: length of the string
  * @next: points to the next node
  */
typedef struct environ_path
{
	char *str;
	unsigned int len;
	struct environ_path *next;
} env_path_t;

env_path_t *add_node(env_path_t **head, char *str, unsigned int len);
env_path_t *list_from_path(void);
void free_list(env_path_t *head);
char *search_os(char *cmd, env_path_t *linkedlist_path);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/* In executor.c */
void executor(char *argv[], env_path_t *linkedlist_path);

/* In memory_management.c */
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void _memset(char *str, int fill, int n);

/* In parser.c */
char *_getline(int file);
char *_strtok(char *str, const char *delim);
char **parser(char *str);
void reader(void);

/* In string_operations.h */
int _strlen(char *s);
int _strncmp(char *s1, char *s2, size_t bytes);
void *_strdup(char *src);
char *_strcat_realloc(char *dest, char *src);


#endif
