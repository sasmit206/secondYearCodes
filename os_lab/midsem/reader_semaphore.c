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
    process *p=shmat(shmid,NULL,0);
    
    sem_wait(&p->mutex);
    p->rc++;
    if(p->rc==1){
        sem_wait(&p->wrt);
    }
    printf("Reader is Reading");
    sem_post(&p->mutex);
    sem_wait(&p->mutex);
    p->rc--;
    if(p->rc==0){
        sem_post(&p->wrt);
    }
    sem_post(&p->mutex);
}