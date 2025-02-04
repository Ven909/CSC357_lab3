#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        printf("Program Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) 
    {
        printf("Error opening file");
        return 1;
    }

    char *line[2] = {NULL, NULL};
    size_t len = 0;
    ssize_t read;
    int count = 0;

    //read = getline(&line[count % 2], &len, fp); 
    
    while ((read = getline(&line[count % 2], &len, fp)) != -1) 
    {
        count++;
    }
  
    fclose(fp);

    // Print the last two lines if available
    if (count == 0) 
    {
        printf("File was empty, nothing to print");
    } 
    else if (count == 1) 
    {
        printf("%s", line[0]);
    } 
    else 
    {
        printf("%s", line[(count - 2) % 2]);
        printf("%s", line[(count - 1) % 2]);
    }

    for(int i = 0; i < 2; i++)
    {
        free(line[i]);
    }

    return 0;
}
