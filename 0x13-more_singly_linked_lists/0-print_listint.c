#include "lists.h"

/**
 * print_listint - Print all elements of a linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: Number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0; /* Initialize a count for nodes */

	/* Traverse the list and print each node's data */
	while (h != NULL)
	{
		printf("%d\n", h->n); /* Print the current node's data */
		h = h->next; /* Move to the next node */
		count++; /* Increment the count of nodes */
	}

	return (count); /* Return the total count of nodes */
}
