/*
============================================================================
Name : 26.c
Author : Aryan Patel
Description :
         Write a program to send messages to the message queue. Check $ipcs -q  
Date: 3 Oct 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

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

    struct msg_buffer message;
    message.msg_type = 1;
    strcpy(message.msg_text, "Hello, Message Queue!");

    if (msgsnd(msqid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }
    printf("Message sent to the queue: %s\n", message.msg_text);
    printf("Now use 'ipcs -q' command to check the message queue status.\n");
    return 0;
}
