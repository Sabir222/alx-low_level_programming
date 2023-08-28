#include "lists.h"

/**
 * add_nodeint_end - Add a new node at the end of a listint_t list.
 * @head: Pointer to a pointer to the head of the list.
 * @n: Integer value to be added to the new node.
 *
 * Return: Address of the new element (node), or NULL if failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *temp; /* Declare new node and temporary node */

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL); /* Return NULL if memory allocation fails */

	new_node->n = n; /* Set the data of the new node */
	new_node->next = NULL; /* Initialize the next pointer of the new node to NULL */

	if (*head == NULL)
		*head = new_node; /* If list is empty, new node becomes the head */
	else
	{
		temp = *head; /* Set temp to the head of the list */

		/* Traverse the list to the last node */
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = new_node; /* Link the last node to the new node */
	}

	return (new_node); /* Return the address of the new node */
}
