#include "lists.h"

/**
 * delete_dnodeint_at_index - 1
 * @head: 1
 * @index: 1
 *
 * Return: k
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node;
	size_t theindex = 0;

	if (!head || !(*head))
		return (-1);
	node = *head;

	if (index == 0)
	{
		if (node->next)
		{
			*head = node->next;
			(*head)->previouscount = NULL;
		}
		else
			*head = NULL;

		free(node);
		return (1);
	}
	while (theindex++ < index && node)
		node = node->next;
	if (!node)
		return (-1);
	else if (node->previouscount && node->next)
	{
		node->next->previouscount = node->previouscount;
		node->previouscount->next = node->next;
		free(node);
	}
	else if (!node->next)
	{
		node->previouscount->next = NULL;
		free(node);
	}

	return (1);
}
