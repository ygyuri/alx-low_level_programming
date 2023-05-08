#include "main.h"

/**
* append_text_to_file – Text is appended at end of the file.
* @filename: Pointer to file’s name.
* @text_content: String is added at file’s end.
*
* Return: - -1 if the function fails or is NULL.
*         - -1 if file is nonexistent user does not have write permission .
*         Otherwise - 1.
*/
int append_text_to_file(const char *filename, char *text_content)
{
int o, w, len = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (len = 0; text_content[len];)
len++;
}

o = open(filename, O_WRONLY | O_APPEND);
w = write(o, text_content, len);

if (o == -1 || w == -1)
return (-1);

close(o);

return (1);
}

