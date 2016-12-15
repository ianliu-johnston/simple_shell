#ifndef UTILS_H
#define UTILS_H

extern char **environ;
int _strlen(char *s);
int _strncmp(char *s1, char *s2, unsigned int bytes);
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void _memset(char *str, int fill, int n);
void *_strdup(char *src);
char *_strcat_realloc(char *dest, char *src);
char *_strtok(char *str, const char *delim);

#endif
