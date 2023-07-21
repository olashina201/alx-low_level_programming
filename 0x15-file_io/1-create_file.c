#include <fcntl.h>
#include <string.h>
#include <unistd.h>

/**
 * create_file - creates a file and write @text_content to that file
 * @filename: the file name as cstring
 * @text_content: pointer to the content of the file as cstring
 * Description:
 * creates file if not exists with permissions 600
 *
 * if no @text_content then just creates the file
 *
 * Return: 1 on success otherwise -1 on fail
 */
int create_file(const char *filename, char *text_content)
{
	int fd, state = -1;

	/* check if no filename return -1 */
	if (!filename)
		goto end;

	/*
	 * if file is not exists then
	 * creates it with permissions 600
	 */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd < 0)
		goto end;

	/*
	 * if @text_content not NULL then
	 * write it as a content to the file
	 */
	if (text_content)
		if (write(fd, text_content, strlen(text_content)) < 0)
			goto end;

	state = 1;
end:
	close(fd);
	return (state);
}

