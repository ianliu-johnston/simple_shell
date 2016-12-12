int _strlen(char *s)
{
	int i;

	for (i = 0; *s; s++, i++)
		;
	return (i);
}
