#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024 // Change this value to modify read size

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        return 1; // Exit if no filename is provided
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) 
    {
        return 1; // Exit if file cannot be opened
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0);

    fclose(file);
    return 0;
}
