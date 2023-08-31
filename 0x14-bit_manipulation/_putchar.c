#include "main.h"
#include <unistd.h>
/**
 * _putchar - hello
 * @c: char
 *
 * Return: 1 success
 * On error, -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
