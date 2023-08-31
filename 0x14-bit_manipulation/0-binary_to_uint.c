#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A string of 0 and 1 chars representing a binary number.
 *
 * Return: The converted number, or 0 if invalid input or b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	/* Initialize variable to store the converted value */
	unsigned int result = 0;
	/* Initialize loop counter */
	unsigned int i = 0;

	/* Return 0 if input string is NULL */
	if (b == NULL)
		return (0);

	/* Iterate through the string until the end */
	while (b[i] != '\0')
	{
		/* Check for invalid characters */
		if (b[i] != '0' && b[i] != '1')
			/* Return 0 if an invalid character is found */
			return (0);

		/* Left shift the result by 1 */
		result <<= 1;
		/* Add the current digit to the result */
		result += (b[i] - '0');
		/* Move to the next character in the string */
		i++;
	}
	/* Return the final converted value */
	return (result);
}

/**
 * main - Check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	/* Declare variable to store the converted value */
	unsigned int n;

	/* Test case: binary string "1" */
	n = binary_to_uint("1");
	printf("%u\n", n);
	/* Test case: binary string "101" */
	n = binary_to_uint("101");
	printf("%u\n", n);
	/* Test case: binary string with invalid character 'e' */
	n = binary_to_uint("1e01");
	/* This line will not execute due to invalid input */
	printf("%u\n", n);
	/* Test case: binary string "1100010" */
	n = binary_to_uint("1100010");
	printf("%u\n", n);
	/* Test case: long binary string */
	n = binary_to_uint("0000000000000000000110010010");
	printf("%u\n", n);
	/* Return 0 to indicate successful execution */
	return (0);
}
