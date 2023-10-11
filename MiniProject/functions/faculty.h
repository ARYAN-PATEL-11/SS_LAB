#ifndef FACULTY_FUNCTIONS
#define FACULTY_FUNCTIONS

#include <sys/ipc.h>
#include <sys/sem.h>
#include<time.h>
#include "server-constants.h"

struct Faculty loggedInFaculty;
struct middleware{
    int myid;
    time_t mytime;
};
struct middleware myDict[100];


int semid;
bool lock_critical_section(struct sembuf *semOp);
bool unlock_critical_section(struct sembuf *sem_op);
int faculty_operation_handler(int connFD);
int add_course(int connFD);
int view_offering_course(int connFD);
int remove_course(int connFD);
int modify_course(int connFD);
int change_password(int connFD);
int logout(int connFD);

int faculty_operation_handler(int connFD){
    if(login_handler(2,connFD,&loggedInFaculty,NULL)){
        key_t semKey = ftok(FACULTY_FILE,loggedInFaculty.id); // Generate a key based on the account number hence, different customers will have different semaphores
        union semun
        {
          int val; // Value of the semaphore
        } semSet;

        int semctlStatus;
        semid = semget(semKey, 1, 0); // Get the semaphore if it exists
        if (semid == -1)
        {
            semid = semget(semKey, 1, IPC_CREAT | 0700); // Create a new semaphore
            if (semid == -1)
            {
                perror("Error while creating semaphore!");
                _exit(1);
            }

            semSet.val = 1; // Set a binary semaphore
            semctlStatus = semctl(semid, 0, SETVAL, semSet);
            if (semctlStatus == -1)
            {
                perror("Error while initializing a binary sempahore!");
                _exit(1);
            }
        }
        ssize_t writeBytes, readBytes;            
        char readBuffer[1000], writeBuffer[1000];
        bzero(writeBuffer, sizeof(writeBuffer));
        strcpy(writeBuffer, LOGIN_SUCCESS);
        while(1){
            strcat(writeBuffer, "\n");
            strcat(writeBuffer, FACULTY_MENU);
            writeBytes = write(connFD, writeBuffer, strlen(writeBuffer));
            if (writeBytes == -1)
            {
                perror("Error while writing FACULTY_MENU to client!");
                return 0;
            }
            bzero(writeBuffer, sizeof(writeBuffer));

            readBytes = read(connFD, readBuffer, sizeof(readBuffer));
            if (readBytes == -1)
            {
                perror("Error while reading client's choice for FACULTY_MENU");
                return 0;
            }

            int choice = atoi(readBuffer);
            switch (choice)
            {
            case 1:
                //view_offering_course(connFD);
                break;
            case 2:
                //add_course(connFD);
                 break;
            case 3: 
                //remove_course(connFD);
                break;
            case 4:
                //modify_course(connFD);
                break;
            case 5:
                //change_password(connFD);
                break;
            case 6:
                //logout(connFD);
                break;    
            default:
                return 0;
            }
        }
    }
    else
    {
        // FACULTY LOGIN FAILED
        return 0;
    }
    return 1;
}



#endif
