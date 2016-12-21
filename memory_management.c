#include "shell.h"
/**
 * _realloc - reallocates memory based on inputs
 * @ptr: pointer to original memory address
 * @old_size: old memory size
 * @new_size: new memory size
 * Return: new memory address
 */
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *tmp, *buff;
	unsigned int i;

	if (ptr == NULL)
	{
		buff = malloc(new_size);
		if (buff == NULL)
			return (NULL);
		return (buff);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		buff = malloc(new_size * sizeof(char));
		tmp = ptr;

		_memset(buff, '\0', new_size);
		for (i = 0; i < old_size; i++)
			buff[i] = tmp[i];
		free(ptr);
		return (buff);
	}
	return (ptr);
}
/**
 * _memset - fills a given string with n number of fill chars
 * @str: string to be filled with fill
 * @fill: the char to put into str
 * @n: the number of chars to fill
 */
void _memset(char *str, int fill, int n)
{
	int i;

	for (i = 0; i < n; i++)
		str[i] = fill;
}
/**
 * _memcpy - copies part or all of string src to string dest
 * @dest: destination string
 * @src: source string
 * @bytes: number of bytes to copy
 */
void _memcpy(char *dest, char *src, unsigned int bytes)
{
	unsigned int i;

	for (i = 0; i < bytes; i++)
		dest[i] = src[i];
}
