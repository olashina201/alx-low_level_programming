#include <fcntl.h>
#include <string.h>
#include <unistd.h>

/**
 * append_text_to_file - appends @text_content if any to an exist file
 * @filename: the file name as cstring
 * @text_content: pointer to the content of the file as cstring
 *
 * Return: 1 if file is exists and content is written if any otherwise -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, state = -1;

	/* check if no filename return -1 */
	if (!filename)
		goto end;

	/*
	 * opens an exist file to append to it
	 */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd < 0)
		goto end;

	/*
	 * if @text_content not NULL then
	 * append it as a content to the file
	 */
	if (text_content)
		if (write(fd, text_content, strlen(text_content)) < 0)
			goto end;

	state = 1;
end:
	close(fd);
	return (state);
}

