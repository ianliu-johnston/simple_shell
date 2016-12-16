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

/**
  * builtin_commands - stuct for function pointers to builtin commands 
  * @cmd_str: commands (env, cd, alias, history, help)
  * @fun: function
  */
typedef struct builtin_commands
{
	char *cmd_str;
	int (*fun)();
} builtin_cmds_t;

/* In builtins.h */
int (*get_cmd_fun(char *cmd))();
int _env(void);
int _exit_with_grace(env_path_t *linkedlist_path, char *buffer);
int _cd(char *str);
int _alias(char *str);
int _history(char *str);
int _help(char *str);

/* in environment.c */
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
char *_strtok_r(char *str, char *delim, char **saveptr);
char **parser(char *str);
void reader(void);

/* In string_operations.c */
int _strlen(char *s);
int _strncmp(char *s1, char *s2, size_t bytes);
void *_strdup(char *src);
char *_strcat_realloc(char *dest, char *src);

#endif
