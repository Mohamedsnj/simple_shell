#include "shell.h"

/**
 * _strlen - the length of a string
 * @s: the string
 *
 * Return: length of string
 */
int _strlen(char *c)
{
	int l = 0;

	if (!c)
		return (0);

	while (*c++)
		l++;
	return (l);
}

/**
 * _strcomp - comparison of two strings.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcomp(char *c1, char *c2)
{
	while (*c1 && *c2)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	if (*c1 == *c2)
		return (0);
	else
		return (*c1 < *c2 ? -1 : 1);
}

/**
 * starts_with - checks if pattern starts with text
 * @text: string to search
 * @pattern: the substring to find
 *
 * Return: address of next char of text or NULL
 */
char *starts_with(const char *text, const char *pattern)
{
	while (*pattern)
		if (*pattern++ != *text++)
			return (NULL);
	return ((char *)text);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *res = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (res);
}
