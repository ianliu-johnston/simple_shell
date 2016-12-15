#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

/* In base_fxns.c */
int executor(char *argv[]);
char **parser(char *str);
void reader(void);
/* In base_fxns_utils.c */
char *_getline(int file);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

#endif
