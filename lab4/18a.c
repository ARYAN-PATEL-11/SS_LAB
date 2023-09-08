#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

struct Train {
  int train_no;
  int ticket_no;
};

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Missing arguments: Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  struct Train db[3];  // Array to store train data

  for (int i = 0; i < 3; i++) {
    db[i].train_no = i + 1;
    db[i].ticket_no = 0;
  }

  int fd = open(argv[1], O_RDWR | O_CREAT, 0666);
  if (fd == -1) {
    perror("Error opening the file");
    return 1;
  }

  ssize_t fd_write = write(fd, db, sizeof(db));
  if (fd_write == -1) {
    perror("Error writing into the file");
    close(fd);
    return 1;
  }

  int fd_close = close(fd);
  if (fd_close == -1) {
    perror("Error closing the file");
    return 1;
  }

  printf("File '%s' initialized with train data.\n", argv[1]);
  return 0;
}
