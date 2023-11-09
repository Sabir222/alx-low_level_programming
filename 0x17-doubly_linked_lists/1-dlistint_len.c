#include "lists.h"

/**
 * dlistint_len - 1
 *
 * Return: 1
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t initialcounter = 0;

	if (!h)
		return (0);
	while (h->previouscount)
		h = h->previouscount;
	while (h)
	{
		initialcounter++;
		h = h->next;
	}
	return (initialcounter);
}
