#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>

typedef struct process{
    char pid[10];
    int at;
    int bt;
    int prior;
}process;

typedef struct data
{
    int no;
    process p[20];
}data;


int main(){
    int shmid=shmget(1234,sizeof(data),0666|IPC_CREAT);
    data* d= shmat(shmid,NULL,0);
    printf("Enter no. of processes : ");
    int n;
    scanf("%d",&n);

    d->no=n;
    printf("Enter process info: \n");
    for(int i=0;i<n;i++){
        printf("Enter PID, AT, BT, Priority : ");
        scanf("%s %d %d %d",d->p[i].pid,&d->p[i].at,&d->p[i].bt,&d->p[i].prior);
        printf("\n");
    }

    pid_t pid=fork();
    if(pid==0){
        execl("./prempSJF","prempSJF",0);
    }
    else{
        wait(NULL);
        printf("Child Sucessfully executed");
    }


}