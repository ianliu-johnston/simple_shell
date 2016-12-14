/* remove this library call later */
#include <string.h>
int _strlen(char *s)
{
	int i;

	for (i = 0; *s; s++, i++)
		;
	return (i);
}
int _strncmp(char *s1, char *s2, size_t bytes)
{
	unsigned int i;

	for (i = 0; s1[i] && s2[i] && s2[i] == s1[i] && i < bytes - 1; i++)
		;
	return (s2[i] - s1[i]);
}
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
/** All Functions below are unimplemented **/
/*** They are all here as place holders ***/
char *_strtok(char *str, const char *delim)
{
	return (strtok(str, delim));
}
