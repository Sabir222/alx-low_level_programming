#include "main.h"

/**
 * create_file - Creates a file with more drama than a soap opera.
 * @filename: A pointer to the name of the file to create, which will soon have a starring role.
 * @text_content: A pointer to a string to write to the file, the script for our epic tale.
 *
 * Return: If the function fails (the plot twist no one saw coming) - -1.
 *         Otherwise, if it's a blockbuster hit - 1.
 */
int create_file(const char *filename, char *text_content)
{
    int fd, w, len = 0;

    if (filename == NULL)
        return (-1); /* Return -1 if filename is NULL (the protagonist is missing!) */

    if (text_content != NULL)
    {
        for (len = 0; text_content[len];)
            len++;
    }

    fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
    w = write(fd, text_content, len);

    if (fd == -1 || w == -1)
        return (-1); /* Return -1 if errors occur (the plot thickens with errors!) */

    close(fd);

    return (1); /* Return 1 if successful (standing ovation! Our story is a hit!) */
}
