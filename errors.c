#include "shell.h"

/**
 *_sput - input string
 * @c: the string
 *
 * Return: Nothing
 */
void _sput(char *c)
{
	int i = 0;

	if (!c)
		return;
	while (c[i] != '\0')
	{
		_eputchar(c[i]);
		i++;
	}
}

/**
 * _sputchar - writes the character s to stderr
 * @s: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _sputchar(char s)
{
	static int n;
	static char buffer[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || n >= WRITE_BUF_SIZE)
	{
		write(2, buffer, n);
		n = 0;
	}
	if (s != BUF_FLUSH)
		buf[n++] = s;
	return (1);
}

/**
 * _putf - writes the character s to given f
 * @s: The character to print
 * @f: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putf(char s, int f)
{
	static int n;
	static char buffer[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || n >= WRITE_BUF_SIZE)
	{
		write(f, buffer, n);
		n = 0;
	}
	if (s != BUF_FLUSH)
		buffer[i++] = s;
	return (1);
}

/**
 *_putsf - prints an input string
 * @c: the string to be printed
 * @f: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsf(char *c, int f)
{
	int n = 0;

	if (!c)
		return (0);
	while (*c)
	{
		n += _putf(*c++, f);
	}
	return (n);
}
