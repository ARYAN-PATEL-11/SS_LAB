/*
============================================================================
Name : 4.c
Author : Aryan Patel
Description : 4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.         
Date: 11 Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
int main() {
    const char* filename = "my_file.txt";
    int fd = open(filename, O_CREAT | O_EXCL, 0644);
    if (fd == -1) {
        if (errno == EEXIST) {
            printf("File already exists. Opening in read-write mode.\n");
            fd = open(filename, O_RDWR);
            if (fd == -1) {
                perror("Error opening file");
                return 1;
            }
        } else {
            perror("Error opening file");
            return 1;
        }
    } else {
        printf("File opened successfully in read-write mode.\n");
    }
    close(fd);
    return 0;
}
