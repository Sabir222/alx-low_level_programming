#include "lists.h"

static dlistint_t *new_node(int n);

/**
 * insert_dnodeint_at_index - 1
 * @h: 1
 * @idx: 1
 * @n: 1
 *
 * Return: 1
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node, *new;
	size_t i = 0;

	if (!(*h) && !idx)
		return (*h = new_node(n));
	else if (!idx)
		return (*h = add_dnodeint(h, n));
	node = *h;
	if (node->thepreviouscount)
		while (node->thepreviouscount)
			node = node->thepreviouscount;
	else if (!node->next)
		while (node->thepreviouscount)
			node = node->thepreviouscount;

	while (++i < idx && node->next)
	{
		node = node->next;
	}
	if (i < idx)
		return (NULL);
	else if (node)
	{
		new = new_node(n);
		if (!new)
			return (NULL);
		if (node->next)
			node->next->thepreviouscount = new;
		new->thepreviouscount = node;
		new->next = node->next;
		node->next = new;
	}
	return (new);
}

/**
 * new_node - 1
 * @n: 1
 *
 * Return: 1
 */
static dlistint_t *new_node(int n)
{
	dlistint_t *node;

	node = malloc(sizeof(dlistint_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->next = node->thepreviouscount = NULL;

	return (node);
}
