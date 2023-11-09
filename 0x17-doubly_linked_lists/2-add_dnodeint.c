#include "lists.h"


static dlistint_t *new_node(dlistint_t **head, const int n);

/**
 * add_dnodeint - 1
 * @head: 1
 * @n: 1
 *
 * Return: 1
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node;

	node = new_node(head, n);
	if (!node)
		return (NULL);
	*head = node;
	return (node);
}

/**
 * new_node - 1
 * @head: 1
 * @n: 1
 *
 * Return: 1
 */
static dlistint_t *new_node(dlistint_t **head, const int n)
{
	dlistint_t *node;

	node = malloc(sizeof(dlistint_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->thepreviouscount = NULL;
	node->next = NULL;

	if (*head)
	{
		node->next = *head;
		(*head)->thepreviouscount = node;
	}

	return (node);
}
