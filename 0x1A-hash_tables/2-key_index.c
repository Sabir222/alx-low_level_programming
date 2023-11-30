#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"

/**
  * key_index - 1
  * @key: 1
  * @size: T1
  *
  * Return: 1
  */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
