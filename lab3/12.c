/*
============================================================================
Name : 12.c
Author : Aryan Patel
Description : 12. Write a program to find out the opening mode of a file. Use fcntl.          
Date: 24 Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(void) {
    int fileMode;
    int fd = open("12.txt", O_RDONLY);
    fileMode = fcntl(fd, F_GETFL);
    if (fileMode == -1)
    {
        printf("You are useless");
        return 0;
    }
    if ((fileMode & O_ACCMODE) == O_RDONLY)
    {
        printf("File opened in read-only mode.\n");
    }
    if ((fileMode & O_ACCMODE) == O_WRONLY)
    {
        printf("File opened in write-only mode.\n");
    }
    if ((fileMode & O_ACCMODE) == O_RDWR) 
    {
        printf("File opened in read-write mode.\n");
    }
    close(fd);
    return 0;
}
