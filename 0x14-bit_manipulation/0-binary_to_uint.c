#include "main.h"

/**
 * binary_to_uint - Don't you love it when 1s and 0s do the tango to become a number?
 * @b: A string that's like a binary fashion show - all 1s and 0s.
 *
 * Return: The magic number after the binary transformation trick!
 */
unsigned int binary_to_uint(const char *b)
{
    int i;
    unsigned int dec_val = 0;

    if (!b)
        return (0);

    for (i = 0; b[i]; i++)
    {
        // When 0s and 1s go on a date, they take the base-2 express!
        if (b[i] < '0' || b[i] > '1')
            return (0);
        
        // 2-step dance move: Slide left and add the current digit's groove!
        dec_val = 2 * dec_val + (b[i] - '0');
    }

    // Ta-da! The binary magic show reveals its decimal form!
    return (dec_val);
}
