#include "main.h"

/**
* create_file – Generate a file.
* @filename: Pointer to generated file’s name.
* @text_content: String to write to file with a pointer.
*
* Return: - -1 if function fails.
*         Otherwise - 1.
*/
int create_file(const char *filename, char *text_content)
{
int fd, w, len = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (len = 0; text_content[len];)
len++;
}

fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
w = write(fd, text_content, len);

if (fd == -1 || w == -1)
return (-1);

close(fd);

return (1);
}


