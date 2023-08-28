#include "lists.h"

/**
 * free_listint - Release your list from its mortal coil (RIP).
 * @head: Pointer to the head of the list that seeks freedom.
 *              (Remember, it's all about pointers and puns.)
 */
void free_listint(listint_t *head)
{
	listint_t *temp; /* The ephemeral placeholder of nodes */

	while (head != NULL)
	{
		temp = head; /* Temporary guardian of the current soul */
		head = head->next; /* Moving on to the afterlife, I mean, next node */
		free(temp); /* Farewell, dear node! You're now in the great memory heap in the sky */
	}
}
