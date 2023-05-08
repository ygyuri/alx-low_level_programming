#include "main.h"
#include <stdlib.h>

/**
* read_textfile- text file is read and printed to STDOUT.
* @filename: texts to be read
* @letters: reads number of letters
* Return: w- total bytes printed and read
*        0 if filename is NULL or functionality fails.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buf;
ssize_t fd;
ssize_t w;
ssize_t t;

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
buf = malloc(sizeof(char) * letters);
t = read(fd, buf, letters);
w = write(STDOUT_FILENO, buf, t);

free(buf);
close(fd);
return (w);
}

