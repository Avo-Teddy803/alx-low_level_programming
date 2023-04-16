#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output.
 * @filename: pointer to the name of the file to read.
 * @letters: number of letters to read and print.
 *
 * Return: number of letters read and printed. If file cannot be opened or read,
 *         return 0. If @filename is NULL, return 0. If @write fails or does not
 *         write the expected amount of bytes, return 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nrd, nwr;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	nrd = read(fd, buf, letters);
	if (nrd == -1)
	{
		close(fd);
		free(buf);
		return (0);
	}

	nwr = write(STDOUT_FILENO, buf, nrd);
	if (nwr == -1 || nwr != nrd)
	{
		close(fd);
		free(buf);
		return (0);
	}

	close(fd);
	free(buf);

	return (nwr);
}
