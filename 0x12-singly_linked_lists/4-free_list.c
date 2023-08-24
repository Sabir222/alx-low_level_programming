#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a linked list and its content.
 * @head: A pointer to the head of the linked list to be freed.
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;  /* Store the next node in 'temp' */
		free(head->str);     /* Free the string in the current node */
		free(head);          /* Free the current node */
		head = temp;         /* Move 'head' to the next node */
	}
}
