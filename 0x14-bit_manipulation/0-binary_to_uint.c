#include "main.h"

/**
 * binary_to_uint - Converting binary to decimal with style!
 * @g: A string that's like a binary fashion show - all 1s and 0s.
 *
 * Return: The magic number after the binary transformation trick!
 */
unsigned int binary_to_uint(const char *g)
{
	int j;
	unsigned int dec_val = 0;

	if (!g)
		return (0);

	for (j = 0; g[j]; j++)
	{
		/* When 0s and 1s go on a date, they take the base-2 express! */
		if (g[j] < '0' || g[j] > '1')
			return (0);
		/* 2-step dance move: Slide left and add the current digit's groove! */
		dec_val = 2 * dec_val + (g[j] - '0');
	}

	/* Ta-da! The binary magic show reveals its decimal form! */
	return (dec_val);
}
