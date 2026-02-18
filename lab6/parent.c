#include<string.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>

struct message{
    long type;
    char x;
};

int main(){
    struct message m;
    int id=msgget(1234,0666 | IPC_CREAT);
    printf("Enter alphabet to be sent to child : ");
    char ch;
    scanf("%c",&ch);
    m.type=1;
    m.x=ch;
    msgsnd(id,&m,sizeof(ch),1);
}