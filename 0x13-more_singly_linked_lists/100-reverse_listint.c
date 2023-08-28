#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: A pointer to the first node of the list.
 *
 * Return: A pointer to the first node of the reversed list.
 *            (Think of this function as a time-traveling potion that
 *             turns the list around, making it walk backward.)
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous = NULL; /* A mysterious figure from the past */
	listint_t *current = *head; /* The present-day wanderer */
	listint_t *next; /* A glimpse into the future */

	while (current != NULL)
	{
		next = current->next; /* The future is uncertain, but we know the next stop */
		current->next = previous; /* The present connects to the past, creating a loop */
		previous = current; /* The past becomes clearer as we move forward */
		current = next; /* The wanderer advances into the unknown */
	}

	*head = previous; /* The final twist in the tale: the first node points to the past */

	return (*head); /* The protagonist of the story returns triumphant */
}
