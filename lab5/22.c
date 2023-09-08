/*
============================================================================
Name : 22.c
Author : Aryan Patel
Description : 22. Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file           
Date: 2 Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(void)
{
	int fd;
	char buff_1[]={"The child is writing in the file.\n"};
	char buff_2[]={"The parent is writing in the file.\n"};
	fd=open("file22.txt",O_CREAT|O_WRONLY,0644);
	if(fd==-1)
	{
		printf("Error opening file");
	}
        if(!fork())
	{
		write(fd,buff_1,sizeof(buff_1));
	}
	else
	{
		write(fd,buff_2,sizeof(buff_2));
	}
	close(fd);
	return 0;
}	
