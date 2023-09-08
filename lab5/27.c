/*
============================================================================
Name : 27.c
Author : Aryan Patel 
Description : 
        27. Write a program to execute ls -Rl by the following system calls
            a. execl
            b. execlp
            c. execle
            d. execv
            e. execvp           
Date: 8 Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Using execl:\n");
    execl("/bin/ls", "ls", "-Rl", NULL);

    printf("Using execlp:\n");
    execlp("ls", "ls", "-Rl", NULL);

    printf("Using execle:\n");
    char *envp[] = { NULL };
    execle("/bin/ls", "ls", "-Rl", NULL, envp);

    printf("Using execv:\n");
    char *args[] = { "/bin/ls", "-Rl", NULL };
    execv("/bin/ls", args);

    printf("Using execvp:\n");
    execvp("ls", args);
    return 0;
}
