#include "lists.h"

/**
 * pop_listint - Pop the head node from a list, sending it off with style.
 * @head: Pointer to a pointer to the head of the list.
 *
 * Return: The data (n) of the popped node, or 0 if list is but a void.
 *               (Imagine this function as a magician making a bunny disappear.)
 */
int pop_listint(listint_t **head)
{
	int data_gone = 0; /* The magical data that vanishes */

	listint_t *temp; /* A temporal wizard to store the current head */

	if (*head == NULL)
		return (data_gone); /* If the list is but a void, vanish without a trace */

	temp = *head; /* Grasp the head with our temporal hands */
	data_gone = temp->n; /* Extract the magical data from the node */
	*head = (*head)->next; /* Shift the head to the next node, watch it go poof! */

	free(temp); /* The node has served its purpose and must now fade away */

	return (data_gone); /* Return the vanishing data, a memory trick like no other */
}
