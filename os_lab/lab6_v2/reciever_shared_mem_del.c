#include<sys/types.h>
#include<sys/msg.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

struct {
    long id;
    char text[100];
}typedef message;

int main(){
    message m;
    int shmid=shmget(1234,1024,0666|IPC_CREAT);
    msgrcv(shmid,&m,sizeof(m),1,0);
    printf("%s",m.text);
}