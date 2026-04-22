#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

#define MAX 100
typedef struct{
    int pid;
    int at;
    int bt;
    int prior;
}process;

void prior_p(process p[],int n){
    int complete=0,time=0;
    int rt[100],wt[100],tat[100],ct[100];
    for(int i=0;i<n;i++){rt[i]=p[i].bt;}
    
    while(complete,n){
        int highest=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=time&&rt[i]>0){ 
                if(highest==-1||p[i].prior<p[highest].prior||(p[i].prior==p[highest].prior&&p[i].at<p[highest].at)){
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
            ct[highest]=time;
            complete++;
        }
    }

    for(int i=0;i<n;i++){
        tat[i]=ct[i]-p[i].at;
        wt[i]=tat[i]-p[i].bt;
    }
    
}

int main(){
    printf("Enter no of processes : ");
    int n;
    scanf("%d",&n);
    process p[MAX];
    for(int i=0;i<n;i++){
        printf("Enter pid,AT,BT : ");
        scanf("%d %d %d %d",&p[i].pid,&p[i].at,&p[i].bt,&p[i].prior);
    }
    prior_p(p,n);

}