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

typedef struct data{
    int no;
    process p[20];
}data;

int main(){
    int shmid=shmget(1234,sizeof(data),0666 );
    data* d=shmat(shmid,NULL,0);
    int n=d->no;

    int tat[100],ct[100],wt[100],rt[100];
    int complete=0,time=0;

    for(int i=0;i<n;i++){
        rt[i]=d->p[i].bt;
        ct[i]=-1;
    }

    while(complete<n){
        int highest=-1;
        for(int i=0;i<n;i++){
            if(d->p[i].at<=time&&rt[i]>0){
                if(highest==-1||d->p[i].prior<d->p[highest].prior||(d->p[i].prior==d->p[highest].prior&&d->p[i].at<d->p[highest].at)){
                    highest=i;
                }
            }
        }
        if(highest==-1){
            time++;
            continue;
        }
        time++;
        rt[highest]--;
        if(rt[highest]==0){
            complete++;
            ct[highest]=time;
        }
    }

    for(int i=0;i<n;i++){
        tat[i]=ct[i] - d->p[i].at;
        wt[i]=tat[i] - d->p[i].bt;
    }

    printf("\nPID\tAT\tBT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("\n%s\t%d\t%d\t%d\t%d\n",d->p[i].pid,d->p[i].at,d->p[i].bt,tat[i],wt[i]);
    }
}