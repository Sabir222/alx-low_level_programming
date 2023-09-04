#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_buffer - Hires a buffer for data storage, 1024 bytes at a time.
 * @file: The name of the lucky file that gets to have its data buffered.
 *
 * Return: A pointer to the freshly hired buffer.
 */
char *create_buffer(char *file)
{
    /* We're about to hire a buffer, hope it doesn't ask for a raise! */
    char *buffer;

    buffer = malloc(sizeof(char) * 1024);

    if (buffer == NULL)
    {
        dprintf(STDERR_FILENO,
                "Oops! Something went wrong. We ran out of buffers for file %s\n", file);
        exit(99); // Our buffer factory went on strike!
    }

    return (buffer); // The new buffer is ready to work!
}

/**
 * close_file - Gives the file descriptor its walking papers.
 * @fd: The file descriptor to be dismissed.
 */
void close_file(int fd)
{
    /* Time to say goodbye to our clingy file descriptor! */
    int c;

    c = close(fd);

    if (c == -1)
    {
        dprintf(STDERR_FILENO, "Oops! We can't close fd %d. It's too clingy!\n", fd);
        exit(100); // File descriptor refused to leave the party!
    }
}

/**
 * main - The great file copying spectacle begins!
 * @argc: The number of arguments our performers have.
 * @argv: An array of pointers to the arguments, the stars of the show.
 *
 * Return: 0 if the act was successful.
 *
 * Description: If the argument count is incorrect, we'll exit with code 97, as in "oops, wrong stage!"
 * If file_from is a no-show or camera-shy, it's exit code 98 for them.
 * If file_to couldn't find a dressing room or had a writer's block, it's exit code 99.
 * If file_to or file_from can't take a hint and leave after the show, it's exit code 100.
 */
int main(int argc, char *argv[])
{
    /* Let the file copying circus begin! */
    int from, to, r, w;
    char *buffer;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97); // Someone forgot their lines, exit stage left!
    }

    buffer = create_buffer(argv[2]);
    from = open(argv[1], O_RDONLY);
    r = read(from, buffer, 1024);
    to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

    do {
        /* The performers are ready to amaze the audience! */
        if (from == -1 || r == -1)
        {
            dprintf(STDERR_FILENO,
                    "Uh-oh, file %s didn't show up for rehearsal!\n", argv[1]);
            free(buffer);
            exit(98); // The show must go on, but not without the main act!
        }

        w = write(to, buffer, r);
        if (to == -1 || w == -1)
        {
            dprintf(STDERR_FILENO,
                    "Oops! File %s refused to accept the script!\n", argv[2]);
            free(buffer);
            exit(99); /*File got stage fright, couldn't write a single line!*/
        }

        r = read(from, buffer, 1024);
        to = open(argv[2], O_WRONLY | O_APPEND);

    } while (r > 0);

    free(buffer);
    close_file(from);
    close_file(to);

    return (0); /*Standing ovation! The file-copying extravaganza was a success!*/
}
