#include "lists.h"

/**
 * sum_dlistint - 1
 * @head: 1
 *
 * Return: 1
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *node;

	if (!head)
		return (0);
	node = head;

	if (!node->next)
		while (node)
		{
			sum += node->n;
			node = node->previouscount;
		}
	else if (!node->previouscount)
		while (node)
		{
			sum += node->n;
			node = node->next;
		}
	else
	{
		while (node->previouscount)
			node = node->previouscount;
		while (node)
		{
			sum += node->n;
			node = node->next;
		}
	}
	return (sum);
}
