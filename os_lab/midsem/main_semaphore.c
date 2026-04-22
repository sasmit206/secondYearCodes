#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<semaphore.h>

typedef struct {
    int rc;
    sem_t wrt;
    sem_t mutex;
}process;

int main(){
    int shmid=shmget(1234,1024,0666|IPC_CREAT);
    process* p=(process*)shmat(shmid,NULL,0);
    printf("enter no of readers and writers");
    pid_t pid;
    pid=fork();
    sem_init(&p->mutex,0,1);
    sem_init(&p->wrt,0,1);
    if(pid==0){
        execl("./reader_semaphore.c","reader_semaphore",0);
        execl("./writer_semaphore.c","writer_sempahore",0);
    }
    else{
        wait(NULL);
        printf("Child executed");
    }
}