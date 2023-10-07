/*
============================================================================
Name : 22.c
Author : Aryan Patel
Description :
         Write a program to wait for data to be written into FIFO within 10 seconds, use select
	 system call with FIFO.  
Date: 3 Oct 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>

int main() {
    const char *fifopath = "22fifo"; 
    mkfifo(fifopath, 0666);
    int fd = open(fifopath, O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    fd_set read_fds;
    struct timeval timeout;
    FD_ZERO(&read_fds);
    FD_SET(fd, &read_fds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    int selectResult = select(fd + 1, &read_fds, NULL, NULL, &timeout);

    if (selectResult == -1) {
        perror("select");
        exit(EXIT_FAILURE);
    } else if (selectResult == 0) {
        printf("No data received within 10 seconds.\n");
    } else {
        char buff[256];
        int bytesRead = read(fd, buff, sizeof(buff));

        if (bytesRead == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Received message: %s\n", buff);
    }

    close(fd);

    return 0;
}
