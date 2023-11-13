#include "lists.h"

/**
 * free_dlistint - 1
 * @head: 1.
 */
void free_dlistint(dlistint_t *head)
{
	if (!head)
		return;
	while (head->thepreviouscount)
		head = head->thepreviouscount;
	while (head->next)
	{
		head = head->next;
		if (head)
			free(head->thepreviouscount);
	}
	if (head)
		free(head);
}
