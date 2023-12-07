#include "main.h"

/**
 * _strcpy - copies a string
 * @des: the destination
 * @srce: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *des, char *srce)
{
	int i = 0;

	if (des == srce || srce == 0)
		return (des);
	while (srce[i])
	{
		des[i] = srce[i];
		i++;
	}
	des[i] = 0;
	return (des);
}

/**
 * _strdup - duplicates a string
 * @s: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *s)
{
	int l = 0;
	char *r;

	if (s == NULL)
		return (NULL);
	while (*s++)
		l++;
	r = malloc(sizeof(char) * (l + 1));
	if (!r)
		return (NULL);
	for (l++; l--;)
		r[l] = *--s;
	return (r);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_puts - prints an input string
 *@c: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *c)
{
        int i = 0;

        if (!c)
                return;
        while (c[i] != '\0')
        {
                _putchar(c[i]);
                i++;
        }
}
