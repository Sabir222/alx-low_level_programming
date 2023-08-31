#include "main.h"

/**
 * obtain_secret_bit - Unveiling secrets: Fetching the mystic bit from its lair!
 * @number: The realm where the mystic bit resides
 * @bit_index: The map to the mystic bit's hidden location
 *
 * Return: The sacred value of the mystic bit we've uncovered!
 */
int obtain_secret_bit(unsigned long int number, unsigned int bit_index)
{
	int secret_val;

	/* Guarding against wandering off the edge of reality. */
	if (bit_index > 63)
		return (-1);

	/* Initiating a communication with the mystical bit using right shift magic! */
	secret_val = (number >> bit_index) & 1;

	/* Finally, revealing the hidden truth to the world! */
	return (secret_val);
}
