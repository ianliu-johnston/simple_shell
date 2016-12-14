#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char _getc(FILE *stream, char *buf)
{
	ssize_t i;

	printf("reading...\n");
	i = read(STDIN_FILENO, buf, 1);
	if (buf[0] == '\n')
	{
		buf[0] = '\0';
		return ('\n');
	}
	if (i != 1)
		printf("read error\n");
	return (buf[0]);
}
size_t _getline(FILE *stream, char *buf, size_t size)
{
	size_t count = 0;
	char c;
	while (_getc(stream, buf) != '\n' && count < size -1)
	{
		count++;
		buf++;
	}
	return count;
}

int main()
{
	char buf[1024];
	size_t count;

	while (1) {
		printf("starting...\n");
		count = _getline(stdin, buf, 1024);
		printf("The line gotten was %s and was %zu chars long.\n", buf, count);
	}
}
