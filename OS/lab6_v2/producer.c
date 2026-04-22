// Write a producer and consumer program in C using FIFO queue. The producer should write
// a set of 4 integers into the FIFO queue and the consumer should display the 4 integers.
#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<sys/ipc.h>


struct message{
    long id;
    int arr[4];
}typedef message;

int main(){
    message m;
    m.id=1;
    printf("Enter elements to be send to consumer : ");
    for(int i=0;i<4;i++){
        scanf("%d",&m.arr[i]);
    }
    int id=msgget(1234,0666|IPC_CREAT);
    msgsnd(id,&m,sizeof(m.arr),0);
}