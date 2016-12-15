#include <stdlib.h>
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
			return(NULL);
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
		for (i = 0; i < old_size; i++)
			buff[i] = tmp[i];
		free(ptr);
		return(buff);
	}
	return (ptr);
}

void _memset(char *str, int fill, int n)
{
	int i;
	for (i = 0; i < n; i++)
		str[i] = fill;
}
/**
  * _strdup - duplicates a string
  * @src: source to copy from
  * Return: pointer to malloc'd space
  **/
void *_strdup(char *src)
{
	int len, i;
	char *dest;

	len = strlen(src);
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
/**
  * _strcat_realloc - concatenates 2 strings and reallocates automatically
  * @dest: destination to copy to
  * @src: source to copy from
  * Return: pointer to concatenated strings
  **/
char *_strcat_realloc(char *dest, char *src)
{
	unsigned int dest_len, src_len, i;

	dest_len = _strlen(dest);
	src_len = _strlen(src);
	dest = _realloc(dest, dest_len, dest_len + src_len + 1);
	if (dest == NULL)
		return (NULL);
	for (i = 0; i < src_len; i++)
	{
		dest[i + dest_len] = src[i];
	}
	dest[i+dest_len] = '\0';
	return (dest);
}
/** All Functions below are unimplemented **/
/*** They are all here as place holders ***/
char *_strtok(char *str, const char *delim)
{
	return (strtok(str, delim));
}
