#include "parser.h"

int main(int ac, char *av[])
{
	reader();
	ac++;
	av++;
	/*
	int bytes_read;
	size_t len;
	char *ps2 = getenv("PS2");

	bytes_read = len = 0;
	while (bytes_read != -1)
	{
		write(STDOUT_FILENO, ps2, strlen(ps2));
		bytes_read = getline(av, &len, stdin);
		printf("%s\n", *av);
	}
	ac++;
	*/
	return (0);
}
