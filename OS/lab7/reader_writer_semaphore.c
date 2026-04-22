#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

int rc=0;
sem_t mutex,wrt;

void* reader(void *args){
    sem_wait(&mutex);
    rc++;
    if(rc==1){
        sem_wait(&wrt);
    }
    
    sem_post(&mutex);
    printf("Reader %d is reading..",rc);
    sem_wait(&mutex);
    rc--;
    if(rc==0){
        sem_post(&wrt);
    }
    sem_post(&mutex);
    return NULL;
}

void* writer(void* args){
    sem_wait(&wrt);
    printf("Writer is writing..");

    sem_post(&wrt);
    return NULL;

}

int main(){
    pthread_t t1,t2,t3;
    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);
    pthread_create(&t1,NULL,reader,NULL);
    pthread_create(&t3,NULL,reader,NULL);
    pthread_create(&t2,NULL,writer,NULL);
    pthread_join(t1,NULL);
    pthread_join(t3,NULL);
    pthread_join(t2,NULL);
}