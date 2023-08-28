#include "lists.h"

/**
 * print_listint_safe - Prints a whimsical linked list even with loops.
 * @head: A pointer to the first enchanting node of the list.
 *
 * Return: The number of magical nodes in the list.
 *               (Think of the linked list as a sequence of magical portals,
 *                and this function as a guide that shows the way.)
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0; /* Count of magical nodes explored */
	const listint_t *portal; /* A magical portal to traverse the realms */

	portal = head; /* The guide starts at the first magical portal */

	while (portal != NULL)
	{
		nodes++; /* The guide counts the magical nodes they've visited */
		printf("[%p] %d\n", (void *)portal, portal->n); /* The portal is shown to the traveler */
		portal = portal->next; /* The guide leads the traveler to the next magical portal */
		if (portal <= head)
		{
			printf("-> [%p] %d\n", (void *)portal, portal->n); /* If the path loops, the guide points it out */
			break;
		}
	}

	if (portal == NULL)
		return (nodes); /* The journey ends when there are no more portals */

	printf("-> [%p] %d\n", (void *)portal, portal->n); /* The guide concludes by pointing to the loop */

	exit(98); /* If the guide loses their way, they exit the realm with a sense of adventure */

	return (nodes); /* The guide shares the number of magical nodes visited */
}
