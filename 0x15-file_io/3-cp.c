#include "main.h" /* Include the header file "main.h". */
#include <stdio.h> /* Include the standard I/O library. */
#include <stdlib.h> /* Include the standard library for memory allocation and other functions. */

char *create_buffer(char *file); /* Function prototype for create_buffer. */
void close_file(int fd); /* Function prototype for close_file. */

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer; /* Declare a character pointer named buffer. */

	buffer = malloc(sizeof(char) * 1024); /* Allocate memory for the buffer. */

	if (buffer == NULL) /* Check if the allocation was successful. */
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99); /* Exit the program with error code 99. */
	}

	return (buffer); /* Return a pointer to the allocated buffer. */
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int c; /* Declare an integer variable named c. */

	c = close(fd); /* Close the file descriptor. */

	if (c == -1) /* Check if the closing operation failed. */
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd);
		exit(100); /* Exit the program with error code 100. */
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w; /* Declare integer variables. */
	char *buffer; /* Declare a character pointer named buffer. */

	if (argc != 3) /* Check if the number of command-line arguments is not 3. */
	{
		dprintf(STDERR_FILENO,
			"Usage: cp file_from file_to\n");
		exit(97); /* Exit the program with error code 97. */
	}

	buffer = create_buffer(argv[2]); /* Call the create_buffer function to allocate a buffer. */
	from = open(argv[1], O_RDONLY); /* Open the source file for reading. */
	r = read(from, buffer, 1024); /* Read data from the source file into the buffer. */
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664); /* Open the destination file for writing. */

	do { /* Start a loop to copy data from source to destination. */
		if (from == -1 || r == -1) /* Check for read errors. */
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer); /* Free the allocated buffer. */
			exit(98); /* Exit the program with error code 98. */
		}

		w = write(to, buffer, r); /* Write data from the buffer to the destination file. */
		if (to == -1 || w == -1) /* Check for write errors. */
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer); /* Free the allocated buffer. */
			exit(99); /* Exit the program with error code 99. */
		}

		r = read(from, buffer, 1024); /* Read more data from the source file into the buffer. */
		to = open(argv[2], O_WRONLY | O_APPEND); /* Open the destination file for appending. */

	} while (r > 0); /* Continue the loop until there's no more data to read. */

	free(buffer); /* Free the allocated buffer. */
	close_file(from); /* Close the source file. */
	close_file(to); /* Close the destination file. */

	return (0); /* Return 0 to indicate successful execution. */
}
