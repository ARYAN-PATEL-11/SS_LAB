/*
============================================================================
Name : 17a.c
Author : Aryan Patel
Description : 17. Write a program to simulate online ticket reservation. Implement write lock Write a program to open a file, 
store a ticket number and exit. 
Write a separate program, to open the file, 
implement write lock, read the ticket number, 
increment the number and print 
the new ticket number then close the file.            
Date: 25 Aug, 2023.
============================================================================
*/
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

  int ticket_no;


int main(int argc, char *argv[]){
   if(argc!=2){
      printf("missing arguments");
      return 1;
   }
   
   ticket_no=5;
   
   int fd = open(argv[1],O_RDWR);
   if(fd==-1){
     perror("Error opening a file");
     return 1;
   }
       
   int fd_write = write(fd,&ticket_no,sizeof(ticket_no));
   if(fd_write==-1){
     perror("Error writing into the file");
     close(fd);
     return 1;
   }
   close(fd);
   
   fd = open(argv[1],O_RDONLY);
   int fd_read = read(fd,&ticket_no,sizeof(ticket_no));
   if(fd_read==-1){
     perror("Error reading the file");
     close(fd);
     return 1;
   }
   
   printf("\nTicket no is:%d",ticket_no);
   close(fd);    
}

