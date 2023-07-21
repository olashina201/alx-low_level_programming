#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - read a file and prints it to stdout
 * @filename: the name of the file
 * @letters: the number of letters to read from the file and print
 *
 * Return: the number of letters printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t counter = 0;
	int fd;

	/* validate inputs */
	if (!filename || !letters)
		goto end;

	/* allocate memory for the data */
	buffer = malloc(letters);
	if (!buffer)
		goto end;

	/* open the required file to read */
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		goto clean;

	/* read file content @letters bytes */
	counter = read(fd, buffer, letters);
	if (counter < 0)
	{
		counter = 0;
		goto close_file;
	}

	/* write the buffer to the standard out */
	counter = write(STDOUT_FILENO, buffer, counter);
	counter = counter > 0 ? counter : 0; /* if failed return 0 */
close_file:
	close(fd); /* close the file stream */
clean:
	free(buffer); /* free the allocated memory */
end:
	return (counter); /* return the amount of data had been written */
}

