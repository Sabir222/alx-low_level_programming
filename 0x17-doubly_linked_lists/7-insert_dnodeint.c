#include "lists.h"

static dlistint_t *new_node(int n);

/**
 * insert_dnodeint_at_index - 1
 * @h: 1
 * @theindex: 1
 * @n: 1
 *
 * Return: 1
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int theindex, int n)
{
	dlistint_t *node, *new;
	size_t vari = 0;

	if (!(*h) && !theindex)
		return (*h = new_node(n));
	else if (!theindex)
		return (*h = add_dnodeint(h, n));
	node = *h;
	if (node->previouscount)
		while (node->previouscount)
			node = node->previouscount;
	else if (!node->next)
		while (node->previouscount)
			node = node->previouscount;

	while (++vari < theindex && node->next)
	{
		node = node->next;
	}
	if (vari < theindex)
		return (NULL);
	else if (node)
	{
		new = new_node(n);
		if (!new)
			return (NULL);
		if (node->next)
			node->next->previouscount = new;
		new->previouscount = node;
		new->next = node->next;
		node->next = new;
	}
	return (new);
}

/**
 * new_node -1
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
	node->next = node->previouscount = NULL;

	return (node);
}
