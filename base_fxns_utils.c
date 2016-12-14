#include "base_fxns.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * _realloc - reallocates memory based on inputs
 *
 * @old_size: old memory size
 * @new_size: new memory size
 * @ptr: pointer to original memory address
 * Return: new memory address
 */
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *tmp, *buff;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	buff = malloc(new_size);
	if (buff == NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		free(ptr);
		return (buff);
	}
	tmp = ptr;
	for (i = 0; i < old_size; i++)
	{
		buff[i] = tmp[i];
	}
	for (; i < new_size; i++)
		buff[i] = '\0';
	free(ptr);
	return (buff);
}

void _memset(char *str, int fill, int n)
{
	int i;
	for (i = 0; i < n; i++)
		str[i] = fill;
}
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
