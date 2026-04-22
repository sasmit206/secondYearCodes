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
    int shmid=shmget(1234,sizeof(data),0666);
    data* d= shmat(shmid,NULL,0);
    int n=d->no;


    //sort this thing first
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(d->p[j].at>d->p[j+1].at){
                process x=d->p[j];
                d->p[j]=d->p[j+1];
                d->p[j+1]=x;
            }
        }
    }

    //now lets do main thing

    int wt[100],ct[100],tat[100],rt[100];
    int complete=0,time=0;

    for(int i=0;i<n;i++){rt[i]=d->p[i].bt;}
    
    while(complete<n){
        int smallest=-1;
        for(int i=0;i<n;i++){
            if(d->p[i].at<=time&&rt[i]>0){
                if(smallest==-1||rt[i]<rt[smallest]||(rt[i]==rt[smallest]&&d->p[i].at<d->p[smallest].at)){
                    smallest=i;
                }
            }
        }
        if(smallest==-1){
            time++;
            continue;
        }
        rt[smallest]--;
        time++;
        if(rt[smallest]==0){
            complete++;
            ct[smallest]=time;
        }
    }

    double awt=0,atat=0;
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-d->p[i].at;
        wt[i]=tat[i]-d->p[i].bt;
        awt+=wt[i];
        atat+=tat[i];
    }
    
    printf("PID\tAT\tBT\tWT\tTAT");
    for(int i=0;i<n;i++){
        printf("\n%s\t%d\t%d\t%d\t%d\n",d->p[i].pid,d->p[i].at,d->p[i].bt,wt[i],tat[i]);
    }
    printf("Avg WT : %.2f Avg TAT : %.2f ",awt,atat);

}