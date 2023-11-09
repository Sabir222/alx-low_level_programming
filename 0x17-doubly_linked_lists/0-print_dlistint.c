#include "lists.h"

/**
 * print_dlistint - 1
 * @h: 1
 *
 * Return: 1
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t thecounter = 0;

	if (!h)
		return (0);

	while (h->thepreviouscount)
		h = h->thepreviouscount;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		thecounter++;
	}
	return (thecounter);
}
