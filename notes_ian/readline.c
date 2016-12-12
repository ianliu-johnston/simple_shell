#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
size_t _getline(char **line, size_t *n, FILE *stream)
{
	line++;
	n++;
	stream++;
}
char *_getenv(const char *name)
{
	name++;
}

int main(int ac, char **av, char **env)
{
	int bytes_read = 0;
	size_t len = 0;

	char *PS2 = getenv("PS2");
	ac++;
	while (bytes_read != -1)
	{
		printf("%s",PS2);
		bytes_read = getline(av, &len, stdin);
		printf("%s\n", *av);
	}
	return (0);
}
