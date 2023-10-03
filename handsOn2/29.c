/*
============================================================================
Name : 29.c
Author : Aryan Patel
Description :
         Write a program to remove the message queue.  
Date: 3 Oct 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    int key;
    int msqid;

    
    key = ftok(".", 'a'); 

    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    msqid = msgget(key, IPC_CREAT|0744);

    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    printf("Message queue removed successfully.\n");

    return 0;
}

