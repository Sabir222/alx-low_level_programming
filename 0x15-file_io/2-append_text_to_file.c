#include "main.h"

/**
 * append_text_to_file - Adds a twist to the end of a story.
 * @filename: A pointer to the name of the story (file).
 * @text_content: The twist to add to the end of the story.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the story (file) does not exist or the user lacks write permissions - -1.
 *         Otherwise, when the twist is successfully added - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int o, w, len = 0;

    if (filename == NULL)
        return (-1); /* Return -1 if there's no story to add a twist to. */

    if (text_content != NULL)
    {
        for (len = 0; text_content[len];)
            len++;
    }

    o = open(filename, O_WRONLY | O_APPEND);
    w = write(o, text_content, len);

    if (o == -1 || w == -1)
        return (-1); /* Return -1 if something went wrong during the twist. */

    close(o);

    return (1); /* Return 1 if the twist was successfully added to the story. */
}
