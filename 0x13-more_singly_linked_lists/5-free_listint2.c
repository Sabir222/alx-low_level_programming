#include "lists.h"

/**
 * free_listint2 - Release a list from the chains of memory, set head to NULL.
 * @head: Pointer to a pointer to the head of the list, the gateway to freedom.
 *          (Think of it as liberating a balloon and then popping it.)
 */
void free_listint2(listint_t **head)
{
	listint_t *temp; /* The courageous temporary guardian of nodes */

	while (*head != NULL)
	{
		temp = *head; /* The chosen one, to be freed */
		*head = (*head)->next; /* Progressing to the next realm, I mean, node */
		free(temp); /* Sending the node to eternal rest in the memory beyond */
	}

	/* The gateway has been shut, and the list is now truly free */
}
