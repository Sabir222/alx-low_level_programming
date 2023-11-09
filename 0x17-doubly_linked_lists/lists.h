#ifndef _LISTS_H_
#define _LISTS_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * struct dlistint_s - 1
 * @n: 1
 * @previouscount: 1e
 * @next: points to the next node
 *
 * Description: 1
 * 
 */
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *previouscount;
	struct dlistint_s *next;
} dlistint_t;


dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);

dlistint_t *add_dnodeint(dlistint_t **head, const int n);
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int theindex, int n);


void free_dlistint(dlistint_t *head);

int sum_dlistint(dlistint_t *head);

size_t dlistint_len(const dlistint_t *h);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
size_t print_dlistint(const dlistint_t *h);

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
#endif
