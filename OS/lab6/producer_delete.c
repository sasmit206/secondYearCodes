#include<string.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdio.h>

struct message {
    long type;
    char sow[200];
};

int main(){
    struct message m;
    int id=msgget(1234,0666 | IPC_CREAT);
    printf("Enter the set of words / sentence :\n");
    scanf("%s",m.sow);
    m.type=1;
    msgsnd(id,&m,sizeof(m.sow),1);
}