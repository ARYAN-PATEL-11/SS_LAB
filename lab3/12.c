#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc , char* argv[]) {
    if(argc!=2){
        printf("You are useless");
        return 0;
    }
    int flags;
    const char *file_path = argv[1];
    int fd = open(file_path, O_WRONLY);//O_RDONLY,O_WRONLY,O_RDWR
    flags = fcntl(fd, F_GETFL); /* Third argument is not required */
    if (flags == -1){
        printf("You are useless");
        return 0;
    }
// Check opening modes
    if ((flags & O_ACCMODE) == O_RDONLY) {
        printf("File opened in read-only mode.\n");
    }
    if ((flags & O_ACCMODE) == O_WRONLY) {
        printf("File opened in write-only mode.\n");
    }
    if ((flags & O_ACCMODE) == O_RDWR) {
        printf("File opened in read-write mode.\n");
    }
    close(fd);
    return 0;
}
