#include "base_fxns.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void _memset(char *str, int fill, int n)
{
	int i;
	for (i = 0; i < n; i++)
		str[i] = fill;
}
char * _getline(int file)
{
        int i;
	char *buffer, *temp;
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
		buffer_size += 1024;
		temp = malloc((buffer_size) * sizeof(char));
		_memset(temp, '\0', buffer_size);
		memcpy(temp, buffer, (buffer_size - 1024));
		free(buffer);
		buffer = temp;
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
