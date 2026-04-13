#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

typedef struct process{
    char pid[10];
    int at;
    int bt;
    int prior;
}process;

typedef struct {
    int no;
    process p[20];
}data;

int main(){
    int n;
    
    printf("Enter no of processes");
    scanf("%d",&n);
    printf("Input process ID, AT, BT, Priority");

    int shmid=shmget(1234,sizeof(data),0666|IPC_CREAT);
    if (shmid < 0) {
    perror("shmget failed");
    exit(1);
    }
    data * d=shmat(shmid,NULL,0);
    d->no=n;

    for(int i=0;i<n;i++){
        scanf("%s %d %d %d",d->p[i].pid,&d->p[i].at,&d->p[i].bt,&d->p[i].prior);
    }
    
    fflush(stdout);
    pid_t pid=fork();
    if(pid==0){
        sleep(1);
        execl("./premPriority","premPriority",NULL);
    }
    else{
        wait(NULL);
        shmctl(shmid, IPC_RMID, NULL);
        printf("Child Executed Successfully");
        printf("Child Executed Sucessfully");
    }

}