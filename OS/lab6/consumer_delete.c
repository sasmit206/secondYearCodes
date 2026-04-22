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
    printf("Displaying the set of words / sentence :\n");
    msgrcv(id,&m,sizeof(m.sow),1,0);
    printf("%s \n",m.sow);
    msgctl(id, IPC_RMID, NULL);
    return 0;
}