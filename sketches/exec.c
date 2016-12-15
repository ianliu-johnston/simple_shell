#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int execute(char *argv[])
{
	*argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	pid_t child_status = 0;

	printf("Beginning\n");

	switch(child_status = fork()) {
	case -1:
		printf("Error.");
		exit(99);
	case 0:
		if (execve(argv[0],argv,NULL) == -1)
			printf("ERROR\n");
		exit(99);
		break;
	default:
		sleep(3);
		break;
	}
	printf("AFTER\n");
	return (0);
}
