#include "lists.h"

/**
 * delete_nodeint_at_index - Removes an element from the mystical list.
 * @head: Pointer to a pointer to the head of the enchanted list.
 * @index: The index of the element to be removed, starting at 0.
 *
 * Return: 1 if the element vanished, or -1 if the void resisted.
 *                (Imagine the list as a collection of magical artifacts, and this function as a dispelling spell.)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int wizard_index = 0; /* The index the magical wizard is on */
	unsigned int spells_cast = 0; /* The number of spells cast to dispel the element */

	listint_t *vanished_element; /* The vanished element, sent to another realm */

	if (*head == NULL)
		return (-1); /* If the list is but a void, the magic can't touch it */

	vanished_element = *head; /* The vanished element reveals itself from the head */
	if (index == 0) /* If the spell is cast on the first element */
	{
		*head = vanished_element->next; /* The void reshapes itself, removing the element */
		free(vanished_element); /* The vanished element is sent to another realm */
		return (1); /* The element has vanished, leaving only whispers of its presence */
	}

	while (vanished_element != NULL)
	{
		if (wizard_index == index - 1) /* The magical wizard is one step before the element to be vanished */
		{
			listint_t *temp = vanished_element->next; /* A scroll to hold the element's position */
			if (temp == NULL)
				return (-1); /* If the wizard steps into the void, the magic fails */

			vanished_element->next = temp->next; /* The element is banished, its energy released */
			free(temp); /* The vanished element fades from memory */
			return (1); /* The element has been successfully dispelled, the magic is triumphant */
		}

		vanished_element = vanished_element->next; /* The wizard steps closer to the element to be vanished */
		wizard_index++; /* The magical wizard's journey progresses */
	}

	return (-1); /* If the element's presence can't be confirmed, the magic falters */
}
