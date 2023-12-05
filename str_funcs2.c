#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *c)
{
	int l = 0;
	char *res;

	if (c == NULL)
		return (NULL);
	while (*c++)
		l++;
	res = malloc(sizeof(char) * (l + 1));
	if (!res)
		return (NULL);
	for (l++; l--;)
		res[l] = *--c;
	return (res);
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
