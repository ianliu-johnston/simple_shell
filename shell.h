#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
/* delete when functions are built */
#include <string.h>
/* end delete when functions are built */

#define BUFSIZE 1024
extern char **environ;
/**
  * struct environ_type - linked list from PATH
  * @str: path in the format /usr/bin
  * @len: length of the string
  * @next: points to the next node
  */
typedef struct environ_type
{
	char *str;
	unsigned int len;
	struct environ_type *next;
} env_t;

/**
  * struct builtin_commands - stuct for function pointers to builtin commands
  * @cmd_str: commands (env, cd, alias, history)
  * @fun: function
  */
typedef struct builtin_commands
{
	char *cmd_str;
	int (*fun)();
} builtin_cmds_t;

/* In builtins.c */
int (*is_builtin(char *cmd))();
int _exit_with_grace(char **tokens, env_t *linkedlist_path, char *buffer);
int _env(char **tokens, env_t *environment);
int _cd(char **tokens);

/* In builtins_2.c */
int _setenv_usr(char **tokens);
int _alias(void);
int _history(void);
int bowie(void);

/* in environment.c */
env_t *list_from_path(void);
env_t *environ_linked_list(void);
char *search_os(char *cmd, env_t *linkedlist_path);

/* in env_operations.c */
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);

/* in linked_list_operations.c */
env_t *add_node(env_t **head, char *str, unsigned int len);
void free_list(env_t *head);


/* In executor.c */
void executor(char *argv[], env_t *linkedlist_path);

/* In memory_management.c */
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void _memset(char *str, int fill, int n);
void _memcpy(char *dest, char *src, unsigned int bytes);

/* In parser.c */
char *_getline(int file);
char **parser(char *str, char *delim);
void reader(void);

/* In strtok.c */
/* Other functions in this file do not need to be referenced elsewhere. */
char *_strtok_r(char *str, char *delim, char **saveptr);

/* In string_operations.c */
int _strlen(char *s);
int _strncmp(char *s1, char *s2, size_t bytes);
char *_strdup(char *src);
char *_strcat_realloc(char *dest, char *src);
int _atoi(char *s);
int _isdigit(int c);

/* In string_operations_2.c */
unsigned int word_count(char *str);
void simple_print(const char *str);
int _strlen_const(const char *s);
size_t print_list(const env_t *h);

#endif
