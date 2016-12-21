#include "shell.h"
/**
 * word_count - counts words given a char delimiter
 * @str: string of words
 * @delim: delimiter chosed by user
 * Return: word count as unsigned int
 */
unsigned int word_count(char *str, char delim)
{
	unsigned int i, wc, flag;

	for (i = 0, wc = 1; str[i]; i++)
	{
	if (str[i] == delim  && flag == 0)
		flag = 1, wc++;
	if (str[i] != delim)
		flag = 0;
	}
	return (wc);
}
/**
 * _strlen_const - strlen for const strings
 * @s: string to be measured
 * Return: length of string
 */
int _strlen_const(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
/**
 * simple_print - allows us to print simple lines
 * @str: const string to print
 */
void simple_print(const char *str)
{
	int len;

	len = _strlen_const(str);
	write(STDOUT_FILENO, str, len);
}
/**
 * _isdigit - checks if chars are digits
 * @c: char to check
 * Return: 1 if yes, 0 if no
 */
int _isdigit(int c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}
