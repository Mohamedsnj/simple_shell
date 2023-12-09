#include "shell.h"

/**
 * start_node - node in the start of the list
 * @tete: head node
 * @s: field of node
 * @n: node index 
 *
 * Return: size of list
 */
list_t *start_node(list_t **tete, const char *s, int n)
{
	list_t *m;

	if (!tete)
		return (NULL);
	m = malloc(sizeof(list_t));
	if (!m)
		return (NULL);
	_memset((void *)m, 0, sizeof(list_t));
	m->n = n;
	if (s)
	{
		m->s = _strdup(s);
		if (!m->s)
		{
			free(m);
			return (NULL);
		}
	}
	m->next = *tete;
	*tete = m;
	return (m);
}

/**
 * end_node -  node in the end
 * @tete: the head of the node
 * @s:  field of the node
 * @n: index of node
 *
 * Return: size 
 */
list_t *end_node(list_t **tete, const char *s, int n)
{
	list_t *m, *no;

	if (!tete)
		return (NULL);

	no = *tete;
	m = malloc(sizeof(list_t));
	if (!m)
		return (NULL);
	_memset((void *)m, 0, sizeof(list_t));
	m->n = n;
	if (s)
	{
		m->s = _strdup(s);
		if (!m->s)
		{
			free(m);
			return (NULL);
		}
	}
	if (no)
	{
		while (no->next)
			no = no->next;
		no->next = m;
	}
	else
		*tete = m;
	return (m);
}

/**
 * print_string - prints string elements of a list_t linked list
 * @p: pointer to first node
 *
 * Return: size 
 */
size_t print_list_str(const list_t *p)
{
	size_t i = 0;

	while (p)
	{
		_puts(p->str ? p->str : "(nil)");
		_puts("\n");
		p = p->next;
		i++;
	}
	return (i);
}

/**
 * del_node - deletes node with index
 * @tete:  pointer to first node
 * @indice: index of node 
 *
 * Return: 1 on success, 0 on failure
 */
int del_node(list_t **tete, unsigned int indice)
{
	list_t *no, *pre;
	unsigned int i = 0;

	if (!tete || !*tete)
		return (0);

	if (!indice)
	{
		no = *tete;
		*tete = (*tete)->next;
		free(no->str);
		free(no);
		return (1);
	}
	no = *tete;
	while (no)
	{
		if (i == indice)
		{
			pre->next = no->next;
			free(no->str);
			free(no);
			return (1);
		}
		i++;
		pre = no;
		no = no->next;
	}
	return (0);
}

/**
 * fr_lst - frees all nodes of a list
 * @t: pointer to head node
 *
 * Return: void
 */
void free_list(list_t **t)
{
	list_t *no, *nx, *tete;

	if (!t || !*t)
		return;
	tete = *t;
	no = tete;
	while (no)
	{
		nx = no->next;
		free(no->str);
		free(no);
		no = nx;
	}
	*t = NULL;
}
