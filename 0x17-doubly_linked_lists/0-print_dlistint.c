#include "lists.h"

/**
 * print_dlistint - 1
 * @h: 1
 *
 * Return: 1
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t initialcounter = 0;

	if (!h)
		return (0);

	while (h->previouscount)
		h = h->previouscount;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		initialcounter++;
	}
	return (initialcounter);
}
