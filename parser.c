#include "shell.h"

char *_getline(int file)
{
	unsigned int i;
	char *buffer;
	static unsigned int total = 0;
	unsigned int buffer_size = 1024;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		perror("malloc for buffer failed\n");
		return (NULL);
	}
	_memset(buffer, '\0', 1024);
	i = read(file, buffer, 1024);
	total += i;
	while (i >= 1024)
	{
		_realloc(buffer, buffer_size, buffer_size + 1024);
		if (buffer == NULL)
		{
			perror("realloc failed\n");
			return (NULL);
		}
		i = read(file, buffer + buffer_size, 1024);
		total += i;
	}
	return (buffer);
}
/**
  * parser - parses a string into tokens
  * @str: string to parse
  * Return: Double pointer to array of tokens
  */
char **parser(char *str)
{
	char **tokenized, *saveptr, *token;
	char *delimit = "\n ";
	unsigned int i, wc, flag;

	for (i = 0, wc = 1; str[i]; i++)
	{
		if (str[i] == ' ' && flag == 0)
			flag = 1, wc++;
		if (str[i] != ' ')
			flag = 0;
	}
	tokenized = malloc((wc + 1) * sizeof(char *));
	if (tokenized == NULL)
	{
		perror("malloc failed\n");
		return (NULL);
	}
	token = _strtok_r(str, delimit, &saveptr);
	tokenized[0] = token;
	printf("Token 0:%s\n", token);
	i = 1;
	while (token)
	{
		token = _strtok_r(NULL, delimit, &saveptr);
		tokenized[i] = token;
		printf("Token %d:%s\n", i, token);
		i++;
	}
	return (tokenized);
}
int is_alias(char *cmd)
{
	cmd++;
	return (0);
}
/**
  * reader - reads user input and forms it into a string.
  */
void reader(void)
{
	char *prompt, *buffer, **tokens;
	env_path_t *linkedlist_path;

	prompt = "And baby says: ";
	linkedlist_path = list_from_path();
	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		buffer = _getline(STDIN_FILENO);
		tokens = parser(buffer);
		if (is_alias(tokens[0]))
			;
		else if (is_builtin(tokens[0]))
			is_builtin(tokens[0])(linkedlist_path, buffer, tokens);
		else
			executor(tokens, linkedlist_path);
	}
}
