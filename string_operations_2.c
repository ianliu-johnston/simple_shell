#include "shell.h"
/**
 * word_count - counts words given a char delimiter
 * @str: string of words
 * Return: word count as unsigned int
 */
unsigned int word_count(char *str)
{
	unsigned int i, wc, flag;
	char *delims = "\n \t";

	for (i = 0, wc = 1, flag = 0; str[i]; i++)
	{
		if (flag == 0 &&
			  (str[i] == delims[0]
			|| str[i] == delims[1]
			|| str[i] == delims[2])
			&& str[i + 1] != delims[0]
			&& str[i + 1] != delims[1]
			&& str[i + 1] != delims[2])
			flag = 1, wc++;
		else
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
