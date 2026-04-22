#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
pthread_mutex_t x;
int i;
int base,max;

int pw(int base,int i){
    int pro=1;
    while(i){
        pro*=base;
        i--;
    }
    return pro;
}

void* func(void * arg){
    while(1){
        pthread_mutex_lock(&x);
        int curr=i;
        i++;
        pthread_mutex_unlock(&x);
        int v=pw(base,curr);
        if(v>max){
            break;
        }
        printf("The val: %d with thread %lu",v,pthread_self());
        //sleep(1000);
        
    }
    return NULL;
}

int main(){
    printf("Enter number, max value");
    scanf("%d %d",&base,&max);
    i=0;

    pthread_mutex_init(&x,NULL);
    pthread_t t1;
    pthread_create(&t1,NULL,func,NULL);
    pthread_t t2;
    pthread_create(&t2,NULL,func,NULL);
    pthread_t t3;
    pthread_create(&t3,NULL,func,NULL);
    pthread_t t4;
    pthread_create(&t4,NULL,func,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
}