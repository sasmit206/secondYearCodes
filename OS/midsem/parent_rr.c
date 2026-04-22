#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/shm.h>

typedef struct {
    char pid[20];
    int at;
    int bt;
    int prior;
} process;

typedef struct {
    int no;
    process p[20];
}data;

int main(){
    printf("Enter no of processes ");
    int n;
    scanf("%d",&n);
    int shmid = shmget(1234,1024,0666|IPC_CREAT);
    data* d=(data*)shmat(shmid,NULL,0);
    d->no=n;
    for(int i=0;i<n;i++){
        printf("Enter pid,AT,BT : ");
        scanf("%s %d %d %d",d->p[i].pid,&d->p[i].at,&d->p[i].bt,&d->p[i].prior);
    }
    
    pid_t pid;
    pid=fork();
    if(pid==0){
        execl("./rr","rr",NULL);
    }
    else{
        wait(NULL);
        printf("Child sucessfully executed");
    }
}