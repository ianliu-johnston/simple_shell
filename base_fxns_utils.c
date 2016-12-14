#include "base_fxns.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char _getc(FILE *stream, char *buf)
{
        ssize_t i;

        i = read(STDIN_FILENO, buf, 1);
        if (buf[0] == '\n')
        {
                buf[0] = '\0';
                return ('\n');
        }
        if (i != 1)
                printf("read error\n");
        return (buf[0]);
}
size_t _getline(FILE *stream, char *buf, size_t size)
{
        size_t count = 0;

        while (_getc(stream, buf) != '\n' && count < size -1)
        {
                count++;
                buf++;
        }
        return count;
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
