#include "lists.h"

/**
 * free_listint_safe - Frees a magical linked list even with loops.
 * @h: A pointer to the head of the mystical list.
 *
 * Return: The size of the list that was freed.
 *                (Imagine the linked list as a tapestry of dreams,
 *                and this function as a spell that unravels it.)
 */
size_t free_listint_safe(listint_t **h)
{
	size_t nodes = 0; /* Count of dream nodes that were freed */
	listint_t *dreamer; /* The dreamer traversing the tapestry */
	listint_t *dream_fragment; /* A fragment of the dream to be freed */

	if (h == NULL)
		return (0); /* If there's no dream, there's nothing to free */

	dreamer = *h; /* The dreamer steps into the tapestry, beginning the journey */

	while (dreamer != NULL)
	{
		nodes++; /* The dreamer counts the nodes they've explored */
		dream_fragment = dreamer; /* The dream fragment is the part they're in */
		dreamer = dreamer->next; /* The dreamer moves forward to explore the next part */
		free(dream_fragment); /* The dream fragment is freed, releasing its magic */
		if (dream_fragment <= dreamer)
		{
			*h = NULL; /* If the dream looped or the dreamer surpassed it, the dream ends */
			break;
		}
	}

	*h = NULL; /* The dream fades away, leaving nothing but emptiness */

	return (nodes); /* The dreamer returns, sharing the number of nodes freed */
}
