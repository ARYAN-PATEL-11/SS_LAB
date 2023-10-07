/*
============================================================================
Name : 30.c
Author : Aryan Patel
Description : Write a program to create a shared memory.
		a) write some data to the shared memory
		b) attach with O_RDONLY and check whether you are able to overwrite.
		c) detach the shared memory
		d) remove the shared memory
Date: 6 Oct 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h> 

int main() {
    int key, shm_id;
    char *shared_memory;
    
    key = ftok(".", 'b');
    
    shm_id = shmget(key, 10, IPC_CREAT | 0744);
    if (shm_id == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
    
    shared_memory = shmat(shm_id, 0, 0);
    if (shared_memory == (char *)-1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }
    
    printf("Enter the text (up to 10 characters): ");
    scanf("%9s", shared_memory); 
    printf("Data read from shared memory: %s\n", shared_memory);

    int read_only_shm_id = shmget(key, 10, 0 | SHM_RDONLY);
    if (read_only_shm_id == -1) {
        perror("shmget (read-only)");
        exit(EXIT_FAILURE);
    }

    char *read_only_memory = shmat(read_only_shm_id, 0, 0);
    if (read_only_memory == (char *)-1) {
        perror("shmat (read-only)");
        exit(EXIT_FAILURE);
    }

    strncpy(read_only_memory, "This should not overwrite!", 10);

    
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    if (shmdt(read_only_memory) == -1) {
        perror("shmdt (read-only)");
        exit(EXIT_FAILURE);
    }

    
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl (IPC_RMID)");
        exit(EXIT_FAILURE);
    }

    printf("Shared memory detached and removed.\n");

    return 0;
}
