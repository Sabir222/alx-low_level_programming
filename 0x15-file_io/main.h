#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>/*loool*/

#include <sys/stat.h>

#include <fcntl.h>
#include <unistd.h>

/* Declarations for functions that make your code sing and dance! */
ssize_t read_textfile(const char *filename, size_t letters);  /* The reading maestro. */
int create_file(const char *filename, char *text_content);    /* The file creator extraordinaire. */
int append_text_to_file(const char *filename, char *text_content);  /* The text-appending virtuoso. */

#endif
