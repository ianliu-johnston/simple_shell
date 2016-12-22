#include "shell.h"
/**
  * executor - executes a command
 (* by searching through PATH
  * @argv: array of tokens, ie. argument vectors
  * @linkedlist_path: PATH in LL form
  * Return: 0 on success, -1 on failure
  */
void executor(char *argv[], env_t *linkedlist_path)
{
	pid_t child_status = 0;
	char *abs_path;

	abs_path = search_os(argv[0], linkedlist_path);
	if (!abs_path)
	{
		perror("command not found\n");
		return;
	}

	switch (child_status = fork())
	{
	case -1:
		perror("fork failed\n");
		break;
	case 0:
		if (execve(abs_path, argv, environ) == -1)
			perror("execution failed\n");
		break;
	default:
		free(abs_path);
		if (wait(NULL) == -1)
			perror("wait failed\n");
		break;
	}
}
