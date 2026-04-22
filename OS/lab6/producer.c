#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct message{
    long type;
    int nums[4];
};

int main(){
    int id= msgget(1234,0666 | IPC_CREAT);
    struct message m;

    for(int i=0;i<4;i++){
        printf("Enter %d no : ",i+1);
        scanf("%d",&m.nums[i]);
    }

    m.type=1;

    msgsnd(id,&m,sizeof(m.nums),0);
    return 0;
}