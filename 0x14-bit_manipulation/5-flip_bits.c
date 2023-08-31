#include "main.h"  /* Including the main header, where the binary circus is in town */

/**
 * flip_bits - Counts the number of bits performing somersaults to switch from n to m
 * @n: The first acrobat number
 * @m: The second acrobat number
 *
 * Return: The count of bits in the daring flipping act
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;  /* The grand spectacle of bitwise acrobatics */

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);  /* The audience applauds as the bits perform their flips! */
}
