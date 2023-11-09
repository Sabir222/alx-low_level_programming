#include "lists.h"

/**
 * dlistint_len - 1
 * @h: 1
 *
 * Return: 1
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t thecounter = 0;

	if (!h)
		return (0);
	while (h->thepreviouscount)
		h = h->thepreviouscount;
	while (h)
	{
		thecounter++;
		h = h->next;
	}
	return (thecounter);
}
