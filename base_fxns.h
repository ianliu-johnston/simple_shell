#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int executor(char *argv[]);
char **parser(char *str);
void reader(void);
size_t _getline(FILE *stream, char *buf, size_t size);
char *_strtok(char *str, const char *delim);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

#endif
