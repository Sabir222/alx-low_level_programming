#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a linked list.
 * @head: A pointer to a pointer to the head of the linked list.
 * @str: The string to be added to the new node.
 *
 * Return: A pointer to the newly added node.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;  /* A pointer to the new node to be added */

	unsigned int len = 0;  /* Variable to store the length of the string */

	while (str[len])
		len++;  /* Calculate the length of the string */

	new = malloc(sizeof(list_t));  /* Allocate memory for the new node */

	if (!new)
		return (NULL);  /* Return NULL if memory allocation fails */

	new->str = strdup(str);  /* Copy the string to the new node */

	new->len = len;  /* Set the length of the string in the new node */

	new->next = (*head);  /* Point the new node to the current head */

	(*head) = new;  /* Set the new node as the new head */

	return (*head);  /* Return a pointer to the new head */
}
