#include "parser.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void parser(void);
{
	char *av;
	int bytes_read = 0;
	size_t len = 0;
	char *PS2 = getenv("PS2");

	av = malloc(sizeof(char));
	while (bytes_read != -1)
	{
		write(STDOUT_FILENO, PS2, _strlen(PS2));
		bytes_read = getline(av, &len, stdin);
		printf("%s\n", *av[0]);
	}
}
