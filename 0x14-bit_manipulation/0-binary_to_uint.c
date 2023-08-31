#include "main.h"
#include <stddef.h> /* For NULL */
#include <stdio.h> /* For printf */

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string of 0 and 1 chars.
 *
 * Return: The converted number, or 0 if invalid input.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL) /* Check if the input string is NULL */
		return (0);

	while (*b) /* Iterate through the string until null terminator */
	{
		if (*b != '0' && *b != '1') /* Check for invalid characters */
			return (0);

		result = result << 1; /* Left shift the current result by 1 */
		if (*b == '1') /* If the current character is '1', add 1 to result */
			result = result + 1;

		b++; /* Move to the next character */
	}

	return (result);
}

/**
 * main - Check the binary_to_uint function.
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned int n;

	n = binary_to_uint("1");
	printf("%u\n", n);
	n = binary_to_uint("101");
	printf("%u\n", n);
	n = binary_to_uint("1e01"); /* Contains an invalid character */
	printf("%u\n", n);
	n = binary_to_uint("1100010");
	printf("%u\n", n);
	n = binary_to_uint("0000000000000000000110010010");
	printf("%u\n", n);
	return (0);
}
