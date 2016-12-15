#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "environment.h"

/* In base_fxns.c */
void executor(char *argv[], env_path_t *linkedlist_path);
char **parser(char *str);
void reader(void);
/* In base_fxns_utils.c */
char *_getline(int file);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

#endif
