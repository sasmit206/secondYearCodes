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
    int id=msgget(1234,0666);
    struct message m;
    msgrcv(id,&m,sizeof(m.nums),1,0);
    printf("The following no.s recievced : ");
    for(int i=0;i<4;i++)
    {
        printf("%d , ",m.nums[i]);
    }
    printf("\n");
}