#include "main.h"  /* Including a treasure map to the main header */

/**
 * set_bit - Because bits have feelings too, and sometimes they want to change
 * @n: The bitiverse where the magic happens
 * @index: The index where the bit is about to have a makeover
 *
 * Return: 1 if the bit successfully transformed, -1 if it got camera-shy
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    /* Checking if the index is within the "bit-le" limits */
    if (index > 63)
	return (-1);

    /* Using the ancient bit-wizardry to give life a bit of twist */
    *n = ((1UL << index) | *n);

    /* The bit confidently struts out of the makeover booth */
    return (1);
}
