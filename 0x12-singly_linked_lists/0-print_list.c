#include <stdio.h>
#include "lists.h"

/**
 * print_list - Prints the elements of a linked list.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	size_t s = 0;  /* Counter for the number of nodes */

	while (h)  /* Loop through the linked list */
	{
		if (!h->str)
			printf("[0] (nil)\n");  /* Print for NULL string */
		else
			printf("[%u] %s\n", h->len, h->str);  /* Print with length and string content */

		h = h->next;  /* Move to the next node */
		s++;  /* Increment the node counter */
	}

	return (s);  /* Return the total number of nodes */
}
