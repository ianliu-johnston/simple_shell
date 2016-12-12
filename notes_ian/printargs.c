#include <stdio.h>

int main(int ac, char *av[])
{
	ac++;
	while (*av)
	{
		printf("%s\n", *av);
		*av++;
	}
	return (0);
}
