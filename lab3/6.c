/*
============================================================================
Name : 6.c
Author : Aryan Patel 
Description : 6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls           
Date: 18 Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    char buffer[1024];
    ssize_t bytesRead;
    while ((bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }
    if (bytesRead == -1) {
        perror("Error reading from STDIN");
        return 1;
    }
    return 0;
}
