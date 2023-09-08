/*
============================================================================
Name : 23.c
Author : Aryan Patel 
Description : 23. Write a program to create a Zombie state of the running program          
Date: 2 Sept, 2023.
============================================================================
*/
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
int main(void)
{
        pid_t childpid=fork();
        if(childpid>0)
        {       
                printf("Parent process %d is executing..\n",getpid());
                sleep(30);
                wait(0);
        }
        else
        {
                printf("Child executed successfully");
        }
        return 0;
}

