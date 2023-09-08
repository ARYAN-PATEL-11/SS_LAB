#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    // Path to the existing file
    const char* filename = "my_file.txt";

    // Open the file with read-write mode and O_EXCL flag
    int fd = open(filename, O_RDWR | O_EXCL);

    if (fd == -1) {
        if (errno == EEXIST) {
            printf("File already exists. Opening in read-write mode.\n");

            // Try opening the file without O_EXCL flag
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


    // Close the file descriptor
    close(fd);

    return 0;
}
