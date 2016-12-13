#include "parser.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int executor(int *ac, char *argv[])
{
	/*
	*argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	*/
	int i;
	pid_t child_status = 0;

	printf("Command: %s\nFlags: ", argv[0]);
	for (i = 0; i < *ac; i++)
		printf("argv[%d]: %s, ", i, argv[i]);
	printf("\n");

	switch(child_status = fork()) {
	case -1:
		printf("Error.");
		exit(99);
	case 0:
		if (execve(argv[0], argv, NULL) == -1)
			printf("ERROR\n");
		exit(99);
		break;
	default:
		sleep(1);
		break;
	}
	printf("AFTER\n");
	return (0);
}

char **parser(int *count, char *str)
{
	unsigned int i, j, wc, flag;
	char **tokenized;

	for (i = 0, wc = 1; str[i]; i++)
	{
		if (str[i] == ' ' && flag == 0)
		{
			flag = 1;
			wc++;
		}
		if (str[i] != ' ')
			flag = 0;
	}
	*count = wc;
	if ((tokenized = malloc((wc * sizeof(char *)) + 1)) == NULL)
		printf("Malloc Error\n"), exit(99);

	for (i = 0, flag = 0; str[i]; i++)
	{
		if (str[i] == ' ' && flag == 0)
			flag = 1;
		if (str[i] != ' ' && str[i + 1] != ' ')
		{
			for (j = 0; str[i + j] && str[i + j] != ' '; j++)
				printf("str[%d] = %c\n", i + j, str[i + j]);
			if ((tokenized[i] = malloc(j * sizeof(char) + 1)) == NULL)
			{
				free(tokenized);
				printf("Malloc Error\n"), exit(99);
			}
			for (j = 0; str[i + j] && str[i + j] != ' '; j++)
			{
				printf("%c\n", str[i+j]);
				tokenized[i][j] = str[i + j];
			}
			tokenized[i][j] = '\0';
			printf("tokenized[%d] = %s\n", i, tokenized[i]);
			i += j;
			flag = 0;
		}
	}
	tokenized[wc + 1] = NULL;
	return (tokenized);
}

void reader(void)
{
	int bytes_read, c;
	int *ac;
	size_t len;
	char *str;
	char **token;
	char *PS2 = getenv("PS2");

	bytes_read =  len = c = 0;
	ac = &c;
	token = malloc(3 * sizeof(void *));
	while (bytes_read != -1)
	{
		write(STDOUT_FILENO, PS2, _strlen(PS2));
		bytes_read = getline(&str, &len, stdin);
		printf("%s\n", str);

		token = parser(ac, str);

		executor(ac, token);
	}
}
