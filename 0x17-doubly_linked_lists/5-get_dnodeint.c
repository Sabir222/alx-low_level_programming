#include "lists.h"

/**
 * get_dnodeint_at_index - 1
 * @head: 1
 * @index: 1
 *
 * Return: 1
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	size_t idx = 0;
	dlistint_t *node;

	if (!head)
		return (NULL);
	node = head;
	if (node->thepreviouscount)
		node = node->thepreviouscount;
	while (idx < index && node)
	{
		node = node->next;
		idx++;
	}
	return (node);
}
