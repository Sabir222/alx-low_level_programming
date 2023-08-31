#include "main.h"

/**
 * print_binary - Printing binary with a bit of flair!
 * @n: The decimal number to transform into binary
 */
void print_binary(unsigned long int n)
{
	int j, flag = 0;
	unsigned long int current;

	/* Preparing to unveil the binary spectacle! */
	for (j = 63; j >= 0; j--)
	{
		/* Summoning the current bit to center stage. */
		current = n >> j;

		/* When the spotlight shines on a brave 1. */
		if (current & 1)
		{
			_putchar('1');
			flag = 1;
		}
		/* If a 0 dares to follow the 1 parade. */
		else if (flag)
			_putchar('0');
	}

	/* The grand finale, starring the lone 0 when all hope is lost. */
	if (!flag)
		_putchar('0');
}
