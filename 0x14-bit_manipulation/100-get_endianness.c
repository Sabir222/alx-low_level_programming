#include "main.h"

/**
 * get_endianness - checks if a machine is little or big endian
 * Return: 0 for big, 1 for little, and -1 for vertically challenged endianness
 */
int get_endianness(void)
{
    unsigned int i = 1;
    char *c = (char *) &i;

    return (*c);  /* The byte contemplates its place in the endianness universe */
}
