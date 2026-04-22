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

void x(){
      printf("Hello");
}

typedef struct {
    int no;
    process p[20];
}data;

  

int main(){
    int tat[100],wt[100],ct[100],rt[100];
    int complete=0,time=0;
    int shmid = shmget(1234,1024,0666|IPC_CREAT);
    data* d=(data*)shmat(shmid,NULL,0);
    int n=d->no;
    int tq;
    printf("Enter Time Quantum : ");
    scanf("%d",&tq);
    for(int i=0;i<n;i++){
        rt[i]=d->p[i].bt;
    }
    while(complete<n){
        int flag=0;
        for(int i=0;i<n;i++){
            if(d->p[i].at<=time&&rt[i]>0){
                flag=1;
                if(rt[i]>tq){
                    time+=tq;
                    rt[i]-=tq;
                }
                else{
                    time+=rt[i];
                    rt[i]=0;
                    complete++;
                    ct[i]=time;
                }
            }
        }
        if(flag==0){
                time++;
        }
    }
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-d->p[i].at;
        wt[i]=tat[i]-d->p[i].bt;
    }

    printf("\nPID\tAT\tBT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("\n%s\t%d\t%d\t%d\t%d\n",d->p[i].pid,d->p[i].at,d->p[i].bt,tat[i],wt[i]);
        x();
    }
}