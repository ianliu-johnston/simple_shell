#include "base_fxns.h"
#include <stdlib.h>
size_t _getline(char **line, size_t *n, FILE *stream)
{
	return (getline(line, n, stream));
}
char *_getenv(const char *name)
{
	return (getenv(name));
}

int _setenv(const char *name, const char *value, int overwrite)
{
	return (setenv(name, value, overwrite));
}
int _unsetenv(const char *name)
{
	return (unsetenv(name));
}
