#include "shell.h"

/**
 * a_error - prints an error message
 * @information: the parameter & return info struct
 * @e: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void a_error(info_t *information, char *e)
{
	_eputs(information->fname);
	_eputs(": ");
	print_d(information->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(infrmationo->argv[0]);
	_eputs(": ");
	_eputs(e);
}

/**
 * print_decimal - function prints a decimal (integer) number 
 * @in: the input
 * @f: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_decimal(int in, int f)
{
	int (*__putchar)(char) = _putchar;
	int i, cnt = 0;
	unsigned int ab, actual;

	if (f == STDERR_FILENO)
		__putchar = _eputchar;
	if (in < 0)
	{
		ab = -in;
		__putchar('-');
		cnt++;
	}
	else
		ab = in;
	cnt = ab;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (ab / i)
		{
			__putchar('0' + actual / i);
			cnt++;
		}
		actual %= i;
	}
	__putchar('0' + actual);
	cnt++;

	return (cnt);
}

/**
 * conv_n - converter function, a clone of itoa
 * @number: number
 * @b: base
 * @f: argument flags
 *
 * Return: string
 */
char *conv_n(long int number, int b, int f)
{
	static char *a;
	static char buf[50];
	char sn = 0;
	char *p;
	unsigned long n = number;

	if (!(f & CONVERT_UNSIGNED) && number < 0)
	{
		n = -number;
		sn = '-';

	}
	a = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buf[49];
	*p = '\0';

	do	{
		*--p = a[n % b];
		n /= b;
	} while (n != 0);

	if (sn)
		*--p = sn;
	return (p);
}

/**
 * rmov_comts - function replaces first instance of '#' with '\0'
 * @buffer: address of the string to modify
 *
 * Return: Always 0;
 */
void rmov_comts(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
		if (buffer[i] == '#' && (!i || buffer[i - 1] == ' '))
		{
			buffer[i] = '\0';
			break;
		}
}
