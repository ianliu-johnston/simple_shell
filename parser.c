#include "shell.h"

char *_getline(int file)
{
	unsigned int i, index;
	char *buffer;
	static unsigned int buffer_size = BUFSIZE;

	buffer = malloc(sizeof(char) * buffer_size);
	if (buffer == NULL)
	{
		perror("malloc for buffer failed\n");
		return (NULL);
	}
	index = 0;
	_memset(buffer, '\0', buffer_size);
	while ((i = read(file, buffer + index, buffer_size - index)) > 0)
	{

		if (i < (buffer_size - index))
		{
			printf("in buffer: %s\n", buffer);
			return (buffer);
		}
		buffer_size *= 2;
		_realloc(buffer, buffer_size, buffer_size / 2);
		if (buffer == NULL)
		{
			perror("realloc failed\n");
			return (NULL);
		}
		index += i;
	}
	if (i == 0)
	{
		printf("EOF happened\n");
		_memcpy(buffer, "exit", 5);
		return (buffer);
	}
	printf("in buffer: %s\n", buffer);
	return (buffer);
}
/**
  * parser - parses a string into tokens
  * @str: string to parse
  * Return: Double pointer to array of tokens
  */
char **parser(char *str, char *delimit)
{
	char **tokenized, *saveptr, *token;
	unsigned int i, wc;

	wc = word_count(str, ' ');
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
	if(cmd == NULL)
		return (1);
	return (0);
}
/**
  * reader - reads user input and forms it into a string.
  */
void reader(void)
{
	char *prompt, *buffer, **tokens;
	env_t *linkedlist_path;
	char *delimit = "\n ";

	prompt = "And baby says: ";
	linkedlist_path = list_from_path();
	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		buffer = _getline(STDIN_FILENO);
		tokens = parser(buffer, delimit);
		if (is_alias(tokens[0]))
			;
		else if (is_builtin(tokens[0]))
			is_builtin(tokens[0])(linkedlist_path, buffer, tokens);
		else
			executor(tokens, linkedlist_path);
		free(tokens);
		free(buffer);
	}
}
