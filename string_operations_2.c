#include "shell.h"

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
int _strlen_const(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
void simple_print(const char *str)
{
	int len;

	len = _strlen_const(str);
	write(STDOUT_FILENO, str, len);
}
