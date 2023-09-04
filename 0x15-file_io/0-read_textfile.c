#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - The Stand-Up Comedy of File Reading!
 * @filename: The file we're about to read (or not, if it's a no-show).
 * @letters: The number of letters we'd like to read (but remember, they're not love letters).
 * Return: The number of characters that dared to perform or 0 if we got stage fright.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	/* Alright, folks, let's raise the curtain and get a file descriptor on stage. */
	ssize_t fd = open(filename, O_RDONLY);

	/* If the file's a no-show or there's some other drama, we exit with a score of 0. */
	if (fd == -1)
		return (0);

	/* Now, let's introduce our superstar actors, the buffer cast! */
	char *buf = malloc(sizeof(char) * letters);

	/* Give it up for our cast as they read their lines from the script. */
	ssize_t t = read(fd, buf, letters);

	/* The moment we've all been waiting for! Let's perform and write to the console. */
	ssize_t w = write(STDOUT_FILENO, buf, t);

	/* Standing ovation! The performance was a hit, so let's clear the stage and free our actors. */
	free(buf);

	/* And last but not least, it's a wrap! We close the curtains on our file descriptor. */
	close(fd);

	/* Drumroll, please! We're done, and we return the number of characters who dared to be on stage. */
	return (w);
}
