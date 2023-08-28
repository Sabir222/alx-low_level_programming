#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new knight into the ranks of the list.
 * @head: Pointer to a pointer to the head of the noble list.
 * @idx: The index where the new knight shall take position.
 * @n: The valor of the new knight.
 *
 * Return: The address of the new knight, or NULL if the position is inaccessible.
 *                (Imagine the list as a medieval kingdom, and this function as the coronation ceremony.)
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int kingdom_size = 0; /* The size of the majestic kingdom */
	unsigned int court_position = 0; /* The desired position in the royal court */

	listint_t *new_knight; /* The brave new knight to join the ranks */
	listint_t *prev_knight; /* The esteemed previous knight to make way */

	/* First, let's find out the size of the kingdom */
	new_knight = *head; /* The adventurer sets off from the head of the kingdom */
	while (new_knight != NULL)
	{
		kingdom_size++; /* Counting the lands explored */
		new_knight = new_knight->next; /* Moving through the kingdom, seeking glory */
	}

	if (idx > kingdom_size)
		return (NULL); /* If the knight seeks to rule beyond the kingdom's borders, deny the quest */

	new_knight = malloc(sizeof(listint_t)); /* Preparing armor and horse for the new knight */
	if (new_knight == NULL)
		return (NULL); /* If the kingdom's treasury is empty, the knight can't be trained */

	new_knight->n = n; /* The new knight is ready, with valor in his heart */

	if (idx == 0) /* If the new knight aspires to the throne itself */
	{
		new_knight->next = *head; /* He climbs atop the throne */
		*head = new_knight; /* And claims the kingdom for himself */
		return (new_knight); /* Return the victorious new knight */
	}

	prev_knight = *head; /* The previous knight in the royal court, the gatekeeper to the desired position */
	while (court_position < idx - 1) /* Until the desired position is reached */
	{
		prev_knight = prev_knight->next; /* The previous knight steps aside */
		court_position++; /* A step closer to the desired position */
	}

	new_knight->next = prev_knight->next; /* The new knight takes his place beside the previous knight */
	prev_knight->next = new_knight; /* And the previous knight acknowledges the new one's presence */

	return (new_knight); /* Return the newly placed knight, ready to serve the kingdom */
}
