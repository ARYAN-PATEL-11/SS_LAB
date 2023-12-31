/*
============================================================================
Name : 20w.c
Author : Aryan Patel
Description :
         Write two programs so that both can communicate by FIFO -Use one way communication(write). 
Date: 3 Oct 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    char buff[50];
    
    int fd = open("myfifo", O_WRONLY);
    if(fd==-1){
      printf("error opening pipe");
      return 1;
    }
    
    printf("Enter the text:\n");
    scanf(" %[^\n]", buff);
    
    int fd_write = write(fd, buff, sizeof(buff));
    if(fd_write==-1){
      perror("returns:");
      close(fd);
      return 1;
    }
  return 1;  
}
