#include "lists.h"

/**
 * sum_dlistint - return the sum of all the elements values.
 * @head: pointer to a linked list.
 *
 * Return: the Sum (int)
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
			node = node->thepreviouscount;
		}
	else if (!node->thepreviouscount)
		while (node)
		{
			sum += node->n;
			node = node->next;
		}
	else
	{
		while (node->thepreviouscount)
			node = node->thepreviouscount;
		while (node)
		{
			sum += node->n;
			node = node->next;
		}
	}
	return (sum);
}
