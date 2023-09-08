/*
============================================================================
Name : 3.c
Author : Aryan Patel
Description : 3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call      
Date: 11 Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    const char* filename = "my_file.txt";
    int fd = creat(filename, 0644);  // 0644 represents file permissions
    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }
    printf("File created successfully with file descriptor: %d\n", fd);
    close(fd);
    return 0;
}
