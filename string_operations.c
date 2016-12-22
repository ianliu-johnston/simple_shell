#include "shell.h"
/**
 * _strlen - replicates strlen from the standard library
 * @s: string to be measured
 * Return: length of string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; *s; s++, i++)
		;
	return (i);
}
/**
 * _strncmp - compares two strings and returns their difference
 * @s1: the first string
 * @s2: the second string
 * @bytes: number of bytes to compare
 * Return: number of bytes that differ
 */
int _strncmp(char *s1, char *s2, size_t bytes)
{
	unsigned int i;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	for (i = 0; s1[i] && s2[i] && s2[i] == s1[i] && i < bytes - 1; i++)
		;
	return (s2[i] - s1[i]);
}
/**
  * _strdup - duplicates a string
  * @src: source to copy from
  * Return: pointer to malloc'd space
  **/
char *_strdup(char *src)
{
	int len, i;
	char *dest;

	if (src == NULL)
		return (NULL);
	len = _strlen(src);
	if (len < 0)
		return (NULL);
	len++;
	dest = malloc((len) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		dest[i] = src[i];
	dest[i - 1] = '\0';
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
	dest[i + dest_len] = '\0';
	return (dest);
}
/**
 * _atoi - converts a string to an integer
 * @s: the input string
 * Return: the converted int
 */
int _atoi(char *s)
{
	int n, sign, result;

	for (n = result = 0, sign = 1; s[n]; n++)
	{
		if (s[n] == '-')
			sign *= -1;
		if (s[n] >= '0' && s[n] <= '9')
			result = 10 * result - (s[n] - '0');
		if (result < 0 && (s[n] < '0' || s[n] > '9'))
			break;
	}
	if (sign > 0)
		result *= -1;
	return (result);
}
