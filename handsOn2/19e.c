/*
============================================================================
Name : 19e.c
Author : Aryan Patel
Description : Create a FIFO file by:
		e)mkfifo library function
Date: 6 Oct 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int result = mkfifo("myfifo", 0666);
    if (result == -1) {
        perror("mkfifo");
        return 1;
    }
    printf("FIFO 'myfifo' created.\n");
    return 0;
}
