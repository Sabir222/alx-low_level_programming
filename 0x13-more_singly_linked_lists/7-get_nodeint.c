#include "lists.h"

/**
 * get_nodeint_at_index - Fetches a node from the list at a magical index.
 * @head: Pointer to the head of the mystical list.
 * @index: The enchanting index of the desired node, starting at 0.
 *
 * Return: The spellbinding node at the given index, or NULL if it's just a mirage.
 *                (Imagine the list as a library of scrolls, and this function is the librarian.)
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int scrolls_read = 0; /* The number of scrolls read */

	/* Traverse the library until we find the desired scroll */
	while (head != NULL)
	{
		if (scrolls_read == index) /* The magical scroll at the desired index! */
			return (head);

		head = head->next; /* Turn to the next scroll */
		scrolls_read++; /* One more scroll read, the librarian keeps count */
	}

	return (NULL); /* The scroll is but a mirage, nowhere to be found */
}
