#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to be create.
 * @text_content: A pointer to a string to write to the file.
 * Return: -1 If the function fails, 1 Otherwise.
 */

int create_file(const char *filename, char *text_content)
{
	int file_d, a, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	file_d = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	a = write(file_d, text_content, len);

	if (file_d == -1 || a == -1)
		return (-1);

	close(file_d);

	return (1);
}

