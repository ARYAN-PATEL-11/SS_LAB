/*
============================================================================
Name : 21.c
Author : Aryan Patel 
Description : 21. Write a program, call fork and print the parent and child process id.           
Date: 2 Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
int main(void)
{
	pid_t pid;
	printf("Process ID of the program is= %d\n",getpid());
        if(!fork())
	{
		printf("In child process. The process ID of child is=%d\n and its parent process ID is = %d\n",getpid(), getppid());
	}
	else{
		printf("In parent process. The process ID of parent is=%d\n", getpid());
	}
	return 0;
}	
