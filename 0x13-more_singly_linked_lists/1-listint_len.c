#include "lists.h"

/**
 * listint_len - Count the number of elements in a linked list.

 * @h: Pointer to the head of the list.

 *
 * Return: Number of elements in the list.

 */
size_t listint_len(const listint_t *h)

{
	size_t count = 0; /* Initialize a count for elements */


	/* Traverse the list and count each element */

	while (h != NULL)

	{
		h = h->next; /* Move to the next element */

		count++; /* Increment the count of elements */

	}

	return (count); /* Return the total count of elements */

}
