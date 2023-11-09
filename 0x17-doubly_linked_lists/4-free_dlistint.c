#include "lists.h"

/**
 * free_dlistint - 1
 * @head: 1
 */
void free_dlistint(dlistint_t *head)
{
	if (!head)
		return;
	while (head->previouscount)
		head = head->previouscount;
	while (head->next)
	{
		head = head->next;
		if (head)
			free(head->previouscount);
	}
	if (head)
		free(head);
}
