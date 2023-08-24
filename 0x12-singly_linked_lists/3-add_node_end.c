#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a linked list.
 * @head: A pointer to a pointer to the head of the linked list.
 * @str: The string to be added to the new node.
 *
 * Return: A pointer to the newly added node.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;  /* A pointer to the new node to be added */
	list_t *temp = *head;  /* A temporary pointer to traverse the list */

	unsigned int len = 0;  /* Variable to store the length of the string */

	while (str[len])
		len++;  /* Calculate the length of the string */

	new = malloc(sizeof(list_t));  /* Allocate memory for the new node */

	if (!new)
		return (NULL);  /* Return NULL if memory allocation fails */

	new->str = strdup(str);  /* Copy the string to the new node */

	new->len = len;  /* Set the length of the string in the new node */

	new->next = NULL;  /* Set the next pointer of the new node to NULL */

	if (*head == NULL)  /* If the list is empty */
	{
		*head = new;  /* Set the new node as the head */
		return (new);
	}

	while (temp->next)
		temp = temp->next;  /* Traverse to the last node */

	temp->next = new;  /* Set the next pointer of the last node to the new node */

	return (new);  /* Return a pointer to the new node */
}
