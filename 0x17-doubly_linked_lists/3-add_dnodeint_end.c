#include "lists.h"


static dlistint_t *new_node(const int n);

/**
 * add_dnodeint_end - 1
 * @head: 1
 * @n: 1
 *
 * Return: 1
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node, *new;

	if (*head)
	{
		node = *head;
		while (node->next)
			node = node->next;
		new = new_node(n);
		if (!new)
			return (NULL);
		node->next = new;
		node->next->previouscount = node;
	}
	else
	{
		node = new_node(n);
		if (!node)
			return (NULL);
		*head = node;
	}
	return (node);
}


/**
 * new_node - 1
 * @n: 
 *
 * Return: a 
 */
static dlistint_t *new_node(const int n)
{
	dlistint_t *node;

	node = malloc(sizeof(dlistint_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->previouscount = NULL;
	node->next = NULL;

	return (node);
}
