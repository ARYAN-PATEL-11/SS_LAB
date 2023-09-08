/*
============================================================================
Name : 10.c
Author : Aryan Patel 
Description : 10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
            a. check the return value of lseek
            b. open the file with od and check the empty spaces in between the data.           
Date: 18th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc , char* argv[]) {
    if (argc!=2){
        printf("You are useless");
        return 0;
    }
    int fd;
    char data1[] = "ABCDEFGHIJ";
    char data2[] = "klmnopqrst";
    fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    // Write the first 10 bytes
    ssize_t bytesWritten = write(fd, data1, sizeof(data1) - 1);
    if (bytesWritten == -1) {
        perror("Error writing data1");
        close(fd);
        return 1;
    }
    // Move the file pointer by 10 bytes using lseek
    off_t newOffset = lseek(fd, 10, SEEK_CUR);
    if (newOffset == -1) {
        perror("Error seeking file pointer");
        close(fd);
        return 1;
    }
    // Write the second 10 bytes at the new file pointer position
    bytesWritten = write(fd, data2, sizeof(data2) - 1);
    if (bytesWritten == -1) {
        perror("Error writing data2");
        close(fd);
        return 1;
    }
    close(fd);

    printf("Data written and file pointer moved successfully.\n");

    return 0;
}
