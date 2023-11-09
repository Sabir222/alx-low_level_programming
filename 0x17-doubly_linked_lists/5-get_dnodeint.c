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
	size_t theindex = 0;
	dlistint_t *node;

	if (!head)
		return (NULL);
	node = head;
	if (node->previouscount)
		node = node->previouscount;
	while (theindex < index && node)
	{
		node = node->next;
		theindex++;
	}
	return (node);
}
