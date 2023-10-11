#ifndef STUDENT_FUNCTIONS
#define STUDENT_FUNCTIONS

#include <sys/ipc.h>
#include <sys/sem.h>
#include <time.h>
#include "server-constants.h"

struct Student loggedInStudent;
struct Enrollment enroll;
int semid;

int student_operation_handler(int connFD);
int Logout(int connFD);
int Change_password(int connFD);
int view_all_courses(int connFD);
int enroll_course(int connFD);
int view_enrolled_courses(int connFD);
int drop_course(int connFD);

int student_operation_handler(int connFD){

    if(login_handler(3,connFD,NULL,&loggedInStudent)){
        
        key_t semKey = ftok(STUDENT_FILE,loggedInStudent.id); // Generate a key based on the account number hence, different customers will have different semaphores
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
            strcat(writeBuffer, STUDENT_MENU);
            writeBytes = write(connFD, writeBuffer, strlen(writeBuffer));
            if (writeBytes == -1)
            {
                // perror("Error while writing STUDENT_MENU to client!");
                return 0;
            }
            bzero(writeBuffer, sizeof(writeBuffer));

            readBytes = read(connFD, readBuffer, sizeof(readBuffer));
            if (readBytes == -1)
            {
                perror("Error while reading client's choice for STUDENT_MENU");
                return 0;
            }

            int choice = atoi(readBuffer);
            switch (choice)
            {
            case 1:
                //view_all_courses(connFD);
                break;
            case 2:
                //enroll_course(connFD);
                 break;
            case 3: 
                //drop_course(connFD);
                break;
            case 4:
                //view_enrolled_courses(connFD);
                break;
            case 5:
                //Change_password(connFD);
                break;
            case 6:
                Logout(connFD);
                break;    
            default:
                return 0;
            }
        }
    }
    else
    {
        // STUDENT LOGIN FAILED
        return 0;
    }
    return 1;
}




int Logout(int connFD){
    ssize_t readBytes, writeBytes;             
    char readBuffer[1000], writeBuffer[10000];
    char tempBuffer[1000];
    write(connFD,LOG_OUT,strlen(LOG_OUT));
    close(connFD);
    return 0;
}



#endif
