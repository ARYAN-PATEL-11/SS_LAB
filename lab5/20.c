/*
============================================================================
Name : 20.c
Author : Aryan Patel 
Description : 20. Find out the priority of your running program. Modify the priority with nice command.            
Date: 2 Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include <sys/resource.h>
void main()
{
    pid_t p = getpriority(PRIO_PROCESS,0);
    printf("Current Priority = %d\n",p);
//    pid_t q = setpriority(PRIO_PROCESS,0,4);           //PRIORITY MODIFICATION USING setpriority(which,who,prio)
    nice(5);                                             //PRIORITY MODIFICATION USING nice()
    pid_t r = getpriority(PRIO_PROCESS,0);
    printf("New Priority = %d\n",r);

}
