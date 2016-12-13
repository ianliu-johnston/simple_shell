#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
char *_strtok(char *str, const char *delim)
{
	str++;
	delim++;
	return (NULL);
}
size_t _getline(char **line, size_t *n, FILE *stream)
{
	line++;
	n++;
	stream++;
	return (0);
}
char *_getenv(const char *name)
{
	name++;
	return (NULL);
}

int _setenv(const char *name, const char *value, int overwrite)
{
	name++;
	value++;
	overwrite++;
	return (0);
}
int _unsetenv(const char *name)
{
	name++;
	return (0);
}
