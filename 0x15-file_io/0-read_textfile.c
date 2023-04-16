#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output.
 * @filename: name of the file to read.
 * @letters: number of bytes to read and print.
 *
 * Return: the number of bytes read and printed, or 0 if an error occurred.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t nrd, nwr;
    char *buf;

    if (!filename)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    buf = malloc(sizeof(char) * letters);
    if (!buf) {
        close(fd);
        return (0);
    }

    nrd = read(fd, buf, letters);
    if (nrd == -1) {
        free(buf);
        close(fd);
        return (0);
    }

    nwr = write(STDOUT_FILENO, buf, nrd);
    if (nwr == -1 || (size_t) nwr != (size_t) nrd) {
        free(buf);
        close(fd);
        return (0);
    }

    free(buf);
    close(fd);

    return (nrd);
}
