/*
============================================================================
Name : 17b.c
Author : Aryan Patel
Description : 17. Write a program to simulate online ticket reservation. Implement write lock
        Write a program to open a file, store a ticket number and exit. Write a separate program, to
        open the file, implement write lock, read the ticket number, increment the number and print
        the new ticket number then close the file.            
Date: 25 Aug, 2023.
============================================================================
*/
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
struct {
   int ticket_no;
}db;

int main(int argc, char *argv[]){

    struct flock lock;
    
    int fd= open(argv[1],O_RDWR);
    if(fd==-1){
      perror("Error opening the file");
      return 1;
    }
    lock.l_type=F_WRLCK;
	  lock.l_whence=SEEK_SET;
	  lock.l_start=0;
	  lock.l_len=0;
	  lock.l_pid=getpid();
	  printf("Before entering the critical section\n");
	  fcntl(fd,F_SETLKW, &lock);
	  printf("Inside Critical Section\n");
	  printf("Press enter to unlock\n");
    read(fd,&db,sizeof(db));
    printf("\nticket no is:%d",db.ticket_no);
    db.ticket_no++;
    lseek(fd,0,SEEK_SET);
    int fd_write = write(fd,&db,sizeof(db));
    if(fd_write==-1){
      perror("Error writing to the file");
      close(fd);
      return 1;
    }
	  getchar();
	  printf("Unlocked\n");
	  lock.l_type=F_UNLCK;
    fcntl(fd,F_SETLK,&lock);
    printf("FINISH");
    close(fd);
    return 0;
}
