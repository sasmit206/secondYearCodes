#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/types.h>

struct message {
    long id;
    long num;
}typedef message;

int main(){
    long id=msgget(1234,0666|IPC_CREAT);
    printf("Enter number to be send & checked for Palindrome ");
    int n;
    scanf("%d",&n);
    message m;
    m.id=1;
    m.num=n;
    msgsnd(id,&m,sizeof(m.num),0);
    printf("Sent : %d",n);
}