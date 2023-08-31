#include "main.h"  /* Including the main header, where the magic begins */

/**
 * clear_bit - Makes a bit rethink its life choices and go from 1 to 0
 * @n: Pointer to the bitiverse where transformations occur
 * @index: Index of the bit that's having a change of heart
 *
 * Return: 1 if the bit saw the light and switched, -1 if it's stuck in limbo
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
    if (index > 63)
	return (-1);

    *n = (~(1UL << index) & *n);  /* Throwing shade at the bit */
    return (1);  /* The bit now has an existential crisis */
}
