#ifndef LISTS_H
#define LISTS_H

/* Include necessary standard libraries */
#include <stdio.h>
#include <stdlib.h>

/* Define a structure for a singly linked list node */
typedef struct listint_s
{
	int n; /* Integer data */
	struct listint_s *next; /* Pointer to the next node */
} listint_t;

/* Function prototypes */

/* Print elements of the list */
size_t print_listint(const listint_t *h);

/* Get the length of the list */
size_t listint_len(const listint_t *h);

/* Add a node at the beginning */
listint_t *add_nodeint(listint_t **head, const int n);

/* Add a node at the end */
listint_t *add_nodeint_end(listint_t **head, const int n);

/* Free the entire list */
void free_listint(listint_t *head);

/* Free the list and set the head to NULL */
void free_listint2(listint_t **head);

/* Remove the first node */
int pop_listint(listint_t **head);

/* Get node at a specific index */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);

/* Calculate sum of node data */
int sum_listint(listint_t *head);

/* Insert node at index */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);

/* Delete node at index */
int delete_nodeint_at_index(listint_t **head, unsigned int index);

/* Reverse the list */
listint_t *reverse_listint(listint_t **head);

/* Print list safely (handles loops) */
size_t print_listint_safe(const listint_t *head);

/* Free list safely (handles loops) */
size_t free_listint_safe(listint_t **h);

/* Find a loop in the list */
listint_t *find_listint_loop(listint_t *head);

#endif
