#include "shell.h"
/**
 * _strchr - checks for a char in a string
 * @s: the string
 * @c: the char being searched for
 * Return: pointer to char on success, NULL on failure
 */
char *_strchr(char *s, char c)
{
	int len, n;

	len = _strlen(s);
	for (n = 0; n < len; n++)
	{
		if (*(s + n) == c)
			return (s + n);
	}
	s = '\0';
	return (s);
}
/**
 * _strspn - gets length of a substring
 *
 * @s: string to be searched
 * @accept: string to match
 * Return: number of matching bytes
 */
unsigned int _strspn(char *s, char *accept)
{
	int s_len, n, result;

	s_len = _strlen(s);
	n = 0;
	result = 0;
	while (n < s_len)
	{
		if (_strchr(accept, *(s + n)))
			result++, n++;
		else
			return (result);
	}
	return (result);
}
char *_strpbrk(char *s, char *accept)
{
	char *temp;

	temp = accept;
	for (; *s!= '\0'; s++)
	{
		while (*accept != '\0')
		{
			if (*s == *accept)
				return (s);
			accept++;
		}
		accept = temp;
	}
	if (*s == '\0')
		return (0);

	return (s);
}
char *_strtok_r(char *s, char *delim, char **save_ptr)
{
        char *token;
        if (s == NULL)
        {
                if (*save_ptr == NULL)
                        return (NULL);
                s = *save_ptr;
        }
        s += _strspn(s, delim);
        if (*s == '\0')
        {
                *save_ptr = NULL;
                return (NULL);
        }
        token = s;
        s = _strpbrk(token, delim);
        if (s == NULL)
                *save_ptr = NULL;
        else
        {
		*s = '\0';
                *save_ptr = s + 1;
        }
        return (token);
}
/**
	token = s;
	s = _strpbrk(token, delim);
	if (s == NULL)
		*saveptr = NULL;
	else
	{
		*s = '\0';
		*saveptr = s + 1;
	}
	return (token);
}
*/
