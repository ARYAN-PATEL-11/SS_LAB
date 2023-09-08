/*
============================================================================
Name : 25.c
Author : Aryan Patel 
Description : 25. Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).         
Date: 2 Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	pid_t pid1,pid2,pid3;
	pid1=fork();
	if(pid1==0)
	{
		sleep(3);
		printf("Inside Child 1 with Process id=%d and Parent Process ID=%d\n",getpid(),getppid());
	}
	else
	{
		pid2=fork();
		if(pid2==0)
		{
	                printf("Inside Child 2 with Process id=%d and Parent Process ID=%d\n",getpid(),getppid());
		}
		else
		{
			pid3=fork();
			if(pid3==0)
			{
		                printf("Inside Child 3 with Process id=%d and Parent Process ID=%d\n",getpid(),getppid());
			}
			else
			{
				sleep(3);
				printf("Waiting for child 2\n");
				waitpid(pid2,WIFEXITED(2), WCONTINUED);
				printf("Inside Parent with Process ID=%d\n",getpid());
			}
		}
	}
	return 0;
}

