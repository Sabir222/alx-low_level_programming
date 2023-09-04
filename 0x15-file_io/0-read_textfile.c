#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read a hilarious text file and make it LOL on STDOUT.
 * @filename: The uproarious text file to be read (or a joke book).
 * @letters: The number of chuckles (letters) to be read.
 *
 * Return: The actual number of laughs (bytes) read and echoed.
 *         0 when the comedy fails or filename is NULL (it's not funny).
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	/* Get ready to store the punchlines (text) */
	char *buf;       /* The joke buffer */
	ssize_t fd;      /* File of endless laughter descriptor */
	ssize_t w;       /* Laughs (bytes) written */
	ssize_t t;       /* Chuckles (bytes) read */

	/* Open the comedy club (file) */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);  /* Show's over, folks! */

	/* Allocate memory for the joke buffer */
	buf = malloc(sizeof(char) * letters);

	/* Let's start reading the punchlines (text) */
	t = read(fd, buf, letters);

	/* Make the audience (STDOUT) LOL */
	w = write(STDOUT_FILENO, buf, t);

	/* Time to clean up the mess (free memory) */
	free(buf);

	/* Close the comedy club (file) */
	close(fd);

	/* Return the number of laughs (bytes) delivered */
	return (w);
}
