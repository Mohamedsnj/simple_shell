#include "shell.h"

/**
 * isInputInteractive - returns true if shell is interactive mode
 * @information: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int isInputInteractive(info_t *information)
{
	return (isatty(STDIN_FILENO) && information->readfd <= 2);
}

/**
 * _delimeter - checks if character is a delimeter
 * @s: the char to check
 * @delimet: the delimeter string
 * Return: 1 if true, 0 if false
 */
int _delimeter(char c, char *delimet)
{
	while (*delimet)
		if (*delimet++ == s)
			return (1);
	return (0);
}

/**
 *_alphabet - checks for alphabetic character
 *@s: The character to input
 *Return: 1 if s is alphabetic, 0 otherwise
 */

int _alphabet(int s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sn = 1, f = 0, o;
	unsigned int rt = 0;

	for (i = 0;  s[i] != '\0' && f != 2; i++)
	{
		if (s[i] == '-')
			sn *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			f = 1;
			rt *= 10;
			rt += (s[i] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (sn == -1)
		o = -rt;
	else
		o = rt;

	return (o);
}

/**
 * _etoi - converts a string to an integer
 * @c: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _etoi(char *c)
{
	int i = 0;
	unsigned long int ret = 0;

	if (*c == '+')
		c++;  
	for (i = 0;  c[i] != '\0'; i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			ret *= 10;
			ret += (s[i] - '0');
			if (ret > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (ret);
}
