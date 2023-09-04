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
    char *buffer_hired;

    buffer_hired = malloc(sizeof(char) * 1024);

    if (buffer_hired == NULL)
    {
        dprintf(STDERR_FILENO,
                "Oops! Something went wrong. We ran out of buffers for file %s\n", file);
        exit(99); // Our buffer factory went on strike!
    }

    return (buffer_hired); // The new buffer is ready to work!
}

/**
 * close_file - Gives the file descriptor its walking papers.
 * @fd: The file descriptor to be dismissed.
 */
void close_file(int fd)
{
    /* Time to say goodbye to our clingy file descriptor! */
    int closure_result;

    closure_result = close(fd);

    if (closure_result == -1)
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
    int performer_from, performer_to, read_result, write_result;
    char *performance_buffer;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97); // Someone forgot their lines, exit stage left!
    }

    performance_buffer = create_buffer(argv[2]);
    performer_from = open(argv[1], O_RDONLY);
    read_result = read(performer_from, performance_buffer, 1024);
    performer_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

    do {
        /* The performers are ready to amaze the audience! */
        if (performer_from == -1 || read_result == -1)
        {
            dprintf(STDERR_FILENO,
                    "Uh-oh, file %s didn't show up for rehearsal!\n", argv[1]);
            free(performance_buffer);
            exit(98); // The show must go on, but not without the main act!
        }

        write_result = write(performer_to, performance_buffer, read_result);
        if (performer_to == -1 || write_result == -1)
        {
            dprintf(STDERR_FILENO,
                    "Oops! File %s refused to accept the script!\n", argv[2]);
            free(performance_buffer);
            exit(99); /*File got stage fright, couldn't write a single line!*/
        }

        read_result = read(performer_from, performance_buffer, 1024);
        performer_to = open(argv[2], O_WRONLY | O_APPEND);

    } while (read_result > 0);

    free(performance_buffer);
    close_file(performer_from);
    close_file(performer_to);

    return (0); /*Standing ovation! The file-copying extravaganza was a success!*/
}
