#include "lists.h"

/**
 * add_nodeint - Add a new node at the beginning of a listint_t list.
 * @head: Pointer to a pointer to the head of the list.
 * @n: Integer value to be added to the new node.
 *
 * Return: Address of the new element (node), or NULL if failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node; /* Declare a new node */

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL); /* Return NULL if memory allocation fails */

	new_node->n = n; /* Set the data of the new node */
	new_node->next = *head; /* Set the next of the new node to the current head */

	*head = new_node; /* Update the head to point to the new node */

	return (new_node); /* Return the address of the new node */
}
