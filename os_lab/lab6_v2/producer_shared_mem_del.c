/*
Write a producer-consumer program in C in which producer writes a set of words into shared
memory and then consumer reads the set of words from the shared memory. The shared
memory need to be detached and deleted after use.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct {
    long id;
    char text[100];
}typedef message;
int main(){
    int shmid=shmget(1234,1024,0666|IPC_CREAT);
    message* m=(message*)shmget(shmid,1024,0);
    printf("Enter message..");
    char txt[100];
    scanf("%s",txt);
    msgsnd(shmid,&m,sizeof(m->text),1);
}