#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_tables.h"

/**
  * hash_table_get - 1
  * @ht: T1
  * @key: Th1
  * Return: T1
  * 1
  */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx = 0;
	hash_node_t *elem = NULL;

	if (ht == NULL || key == NULL)
		return (NULL);

	idx = key_index((unsigned char *) key, ht->size);
	elem = ht->array[idx];

	if (elem == NULL)
		return (NULL);

	while (strcmp(key, elem->key) != 0)
		elem = elem->next;

	return (elem->value);
}
