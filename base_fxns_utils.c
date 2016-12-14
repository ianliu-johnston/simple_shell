#include "base_fxns.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
char * _getline(int file)
{
	unsigned int i;
	char *buffer;
	static unsigned int total = 0;
	unsigned int buffer_size = 1024;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		printf("malloc for buffer failed\n");
		return (NULL);
	}
	_memset(buffer, '\0', 1024);
	i = read(STDIN_FILENO, buffer, 1024);
	total += i;
	while (i >= 1024)
	{
		_realloc(buffer, buffer_size, buffer_size + 1024);
		if (buffer == NULL)
		{
			printf("realloc failed\n");
			return (NULL);
		}
		i = read(STDIN_FILENO, buffer + (buffer_size - 1024), 1024);
		total += i;
	}
	i = 0;
	while (i <= total)
	{
		if (buffer[i] == ';' || buffer[i] == EOF || buffer[i] == '\n')
			buffer[i] = '\0';
		i++;
	}
	i = 0;
	while (buffer[i] != '\0')
		i++;
	return (buffer);
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
