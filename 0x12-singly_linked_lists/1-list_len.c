#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Counts the number of nodes in a linked list.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t list_len(const list_t *h)
{
	size_t n = 0;  /* Counter for the number of nodes */

	while (h)  /* Loop through the linked list */
	{
		n++;  /* Increment the node counter */
		h = h->next;  /* Move to the next node */
	}

	return (n);  /* Return the total number of nodes */
}
