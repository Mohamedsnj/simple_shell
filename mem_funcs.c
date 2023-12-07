#include "main.h"

/**
 **_memoset - fills memory with a constant byte
 *@c: the pointer to the memory area
 *@m: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memoset(char *c, char m, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		c[i] = m;
	return (c);
}

/**
 * pfree - frees a string of strings
 * @ptr: string of strings
 */
void pfree(char **ptr)
{
	char **tmp = ptr;

	if (!ptr)
		return;
	while (*ptr)
		free(*ptr++);
	free(tmp);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @os: byte size of previous block
 * @ns: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int os, unsigned int ns)
{
	char *s;

	if (!ptr)
		return (malloc(ns));
	if (!ns)
		return (free(ptr), NULL);
	if (ns == os)
		return (ptr);

	s = malloc(ns);
	if (!s)
		return (NULL);

	os = os < ns ? os : ns;
	while (os--)
		s[os] = ((char *)ptr)[os];
	free(ptr);
	return (s);
}

/**
 * afree - frees a pointer and NULLs the address
 * @p: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int afree(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
