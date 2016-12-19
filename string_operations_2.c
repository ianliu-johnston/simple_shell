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
