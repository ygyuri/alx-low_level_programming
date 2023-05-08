#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void close_file(int fd);
char *create_buffer(char *file);


/**
* create_buffer – Assigns a total of 1024 bytes for a buffer.
* @file: The File buffer’s  name.
*
* Return: Pointer to the assigned buffer.
*/
char *create_buffer(char *file)
{
char *buffer;

buffer = malloc(sizeof(char) * 1024);

if (buffer == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", file);
exit(99);
}

return (buffer);
}

/**
* close_file – The File descriptors are closed by this function.
* @fd: The particular file descriptor being closed.
*/
void close_file(int fd)
{
int c;

c = close(fd);

if (c == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
* main – Duplicates to a new file the contents of another file.
* @argc: Total arguments used in the program.
* @argv: Pointer of arrays to the arguments.
* Return: 0 if it does not fail.
* *
* Description: If the count of argument is not correct - withdraw code 97.
* If the file from is not readable or nonexistent - withdraw code 98.
* If the file to is unable to be written to or created - withdraw code 99.
* If file_to or file_from is unable to be closed – withdraw code 100.
*/
int main(int argc, char *argv[])
{
int from, to, r, w;
char *buffer;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buffer = create_buffer(argv[2]);
from = open(argv[1], O_RDONLY);
r = read(from, buffer, 1024);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
if (from == -1 || r == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}

w = write(to, buffer, r);
if (to == -1 || w == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}

r = read(from, buffer, 1024);
to = open(argv[2], O_WRONLY | O_APPEND);

} while (r > 0);

free(buffer);
close_file(from);
close_file(to);

return (0);
}

