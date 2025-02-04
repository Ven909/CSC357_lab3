#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024 // Change this value to modify read size

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        printf("Program Usage: %s <filename>\n", argv[0]);
        return 1; // Exit if no filename is provided
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) 
    {
        printf("Error opening file\n");
        return 1; // Exit if file cannot be opened
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0);
    
    close(fd);
    return 0;
}
