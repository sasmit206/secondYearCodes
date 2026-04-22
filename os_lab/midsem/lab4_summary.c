/*
Write a C program that:
Takes an integer n from the user.
Creates 2 threads using pthread_create().
Both threads access a shared counter variable.
Thread 1 increments the counter n times
Thread 2 decrements the counter n times
Use a mutex (pthread_mutex_lock, pthread_mutex_unlock) to ensure correct synchronization.
The main thread should:
Wait for both threads using pthread_join()
Print the final value of the counter
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int n,c;
pthread_mutex_t op;
void* inc(void* arg){
    for(int i=0;i<n;i++){
        pthread_mutex_lock(&op);
        c++;
        printf("%d INC ",c);
        pthread_mutex_unlock(&op);
    }
    return NULL;
}
void* dec(void* arg){
    for(int i=0;i<n;i++){
        pthread_mutex_lock(&op);
        c--;
        printf("%d DEC ",c);
        pthread_mutex_unlock(&op);
    }
    return NULL;
}

int main(){
    
    printf("Enter no");
    scanf("%d",&n);
    pthread_t t1,t2;
    pthread_mutex_init(&op,NULL);
    c=0;
    pthread_create(&t1,NULL,inc,NULL);
    pthread_create(&t2,NULL,dec,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("%d",c);
}