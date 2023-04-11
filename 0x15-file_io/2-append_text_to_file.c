#include "main.h"

/**
 * append_text_to_file - append texts.
 * @filename: A filename pointer.
 * @text_content: The string to add to eof.
 *
 * Return: -1 If the function fails or filename is NULL.
 * 1 If the file does not exist, no write permissions.
 * Otherwise - 1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int o, a, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	a = write(o, text_content, len);

	if (o == -1 || a == -1)
		return (-1);

	close(o);

	return (1);
}
