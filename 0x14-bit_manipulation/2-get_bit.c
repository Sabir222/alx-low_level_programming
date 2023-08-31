#include "main.h"

/**
 * get_bit - Seeking the truth behind the bits!
 *
 * @n: The keeper of the bits
 * @index: The index to peer into the bit realm
 *
 * Return: The revelation of the bit's hidden value
 */
int get_bit(unsigned long int number, unsigned int index)
{
	int thebit_value;

	if (index > 63)
		return (-1);  /* Beyond this index, only the brave tread */

	thebit_value = (number >> index) & 1;  /* Unveiling the mystery of the chosen bit */

	return (thebit_value);
}
