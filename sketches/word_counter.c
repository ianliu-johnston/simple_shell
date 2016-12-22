#include <stdio.h>
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
	wc--;
	return (wc);
}

int main(void)
{
	unsigned int wc;
	size_t size;
	char *buffer;

	printf("~> ");
	getline(&buffer, &size, stdin);
	wc = word_count(buffer);
	printf("Word count: %u\n", wc);
	return (0);
}
