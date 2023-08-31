#ifndef MAIN_H
#define MAIN_H

/** @brief Converts binary to a number without asking "Are you a 1 or a 0?" */
unsigned int binary_to_uint(const char *b);

/** @brief Turns a number into a binary fashion show */
void print_binary(unsigned long int n);

/** @brief Retrieves a bit's attention by its index */
int get_bit(unsigned long int n, unsigned int index);

/** @brief Sets a bit on a coffee break */
int set_bit(unsigned long int *n, unsigned int index);

/** @brief Clears a bit's confusion by providing directions */
int clear_bit(unsigned long int *n, unsigned int index);

/** @brief Flips bits like a pancake chef flipping breakfast */
unsigned int flip_bits(unsigned long int n, unsigned long int m);

/** @brief Converts a string into an integer, because strings can't adult */
int _atoi(const char *s);

/** @brief Outputs a character, because sometimes bytes just want to be heard */
int _putchar(char c);

/** @brief Checks the endianness of the system while endearing it with cuteness */
int get_endianness(void);

#endif
