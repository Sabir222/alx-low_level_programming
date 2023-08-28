#include "lists.h"

/**
 * free_listint_safe - Releases a linked list, freeing its members
 * and setting itself free... like a henchman plotting its escape!
 * @h: A pointer to the first node in the linked list.
 *
 * Return: The count of nodes that experienced the taste of freedom.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t freedom_count = 0; /* Counting the moments of liberation */
	int escape_route; /* A secretive path to evasion */
	listint_t *liberated_node; /* The valiant liberator of nodes */

	if (!h || !*h)
		return (0);

	while (*h)
	{
		escape_route = *h - (*h)->next; /* The daring breakout distance */
		if (escape_route > 0)
		{
			liberated_node = (*h)->next; /* The next stop on the path to freedom */
			free(*h); /* Releasing one node into the wild */
			*h = liberated_node; /* Pointing towards the route of escape */
			freedom_count++; /* Another node breaks the chains */
		}
		else
		{
			free(*h); /* A final act of courage, setting itself free */
			*h = NULL; /* Erasing all evidence of its former existence */
			freedom_count++; /* The last act in the grand escape */
			break; /* The tale ends, with a triumphant escape */
		}
	}

	*h = NULL; /* Ensuring no lingering ties to the past */

	return (freedom_count); /* The sum of nodes that have tasted liberty */
}
