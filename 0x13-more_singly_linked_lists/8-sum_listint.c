#include "lists.h"

/**
 * sum_listint - Adds up the mystical energy of a list's elements.
 * @head: Pointer to the head of the enchanting list.
 *
 * Return: The magical sum of the list's elements, or 0 if the list is but a void.
 *                (Imagine each element as a sprinkle of fairy dust, and this function as the collector.)
 */
int sum_listint(listint_t *head)
{
	int magical_sum = 0; /* The accumulating magic sum */

	/* Traverse the realm of the list, collecting magical energy */
	while (head != NULL)
	{
		magical_sum += head->n; /* Adding the magical energy of each element */
		head = head->next; /* Moving to the next element, gathering more energy */
	}

	return (magical_sum); /* The total magical energy collected, ready for use */
}
