#include "shell.h"
#include <stdio.h>

int main(void)
{
	write(STDOUT_FILENO, "Dance Magic Dance\n", 18);
	reader();
	return (0);
}
