#include<stdlib.h>
#include<stdio.h>


typedef struct process{
    int pid;
    int at;
    int bt;
}process;

void sort(process p[],int n){
    for(int i=0;i<n;i++){
        process temp=p[i];
        for(int j=0;j<n-i-1;j++){
            if(p[j].pid>p[j+1].pid){
                process x=p[j];
                p[j]=p[j+1];
                p[j+1]=x;
            }
        }
    }
}

void rr(process p[],int n){
    int tat[100],wt[100],ct[100],rt[100];
    int completed=0,time=0,tq;
    printf("Enter Time Quantum for RR : ");
    scanf("%d",&tq);
    
    for(int i=0;i<n;i++){rt[i]=p[i].bt;}

    while(completed<n){
        int flag=0;
        for(int i=0;i<n;i++){
            
            if(p[i].at<=time&&rt[i]>0){
                flag=1;
                if(rt[i]>tq){
                    rt[i]-=tq;
                    time+=tq;
                }
                else{
                    time+=rt[i];
                    ct[i]=time;
                    rt[i]=0;
                    completed++;
                }   
            }
        }
        if(flag==0){time++;}
    }
    double atat=0,awt=0;
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-p[i].at;
        wt[i]=tat[i]-p[i].bt;
        atat+=tat[i];
        awt+=wt[i];
    }

    printf("PID\tAT\tBT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t %d\t %d\t %d\t %d\n",p[i].pid,p[i].at,p[i].bt,tat[i],wt[i]);
    }
    printf("Avg Wt time: %.2f Avg TAT: %.2f",awt/n,atat/n);

}

void priority_p(process p[],int n){
    int rt[100],wt[100],tat[100],ct[100];
    int time=0;
    int completed=0;
    for(int i=0;i<n;i++){rt[i]=p[i].bt;}

    while(completed<n){
        int highest = -1;
        for(int i=0;i<n;i++){
            if(p[i].at<=time&&rt[i]>0){
                if(highest==-1||p[i].pid>p[highest].pid||(p[i].pid==p[highest].pid&&p[i].at<p[highest].at)){
                    highest=i;
                }
            }
        }

        if(highest==-1){
            time++;
            continue;
        }

        rt[highest]--;
        time++;

        if(rt[highest]==0){
            completed++;
            ct[highest]=time;
        }
    }
}

void priority_np(process p[],int n){
    int wt[100],tat[100],ct[100];
    int time=0,rt[100];
    int completed=0;

    for(int i=0;i<n;i++){rt[i]=p[i].bt;}

    while(completed<n){
        int highest=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=time&&rt[i]>0){
                if(highest==-1||p[i].pid>p[highest].pid||(p[i].pid==p[highest].pid&&p[i].at<p[highest].at)){
                    highest = i;
                }
            }
        }
        if(highest==-1){
            time++;
            continue;
        }
        time+=rt[highest];
        rt[highest]=0;
        ct[highest]=time;
        completed++;
    }
    double atat=0,awt=0;
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-p[i].at;
        wt[i]=tat[i]-p[i].bt;
        atat+=tat[i];
        awt+=wt[i];
    }
    printf("\nAvg WT: %.2f | Avg. TAT : %.2f\n",awt/n,atat/n);
    printf("\nPID\tAT\tBT\tWT\tTAT");
    for(int i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,wt[i],tat[i]);
    }
}

void fcfs(process p[],int n){
    int wt[100],ct[100],tat[100];
    int time=0,completed=0;
    
    ct[0]=p[0].bt;
    for(int i=0;i<n;i++){
        ct[i]=(ct[i-1]>p[i].at?ct[i-1]:p[i].at)+p[i].bt;
    }
    double atat=0,awt=0;
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-p[i].at;
        wt[i]=tat[i]-p[i].bt;
        atat+=tat[i];
        awt+=wt[i];
    }
    printf("%.2f Avg TAT %.2f is AWT",atat/n,awt/n);
    printf("\nPID\tAT\tBT\tWT\tTAT");
    for(int i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,wt[i],tat[i]);
    }
}

void sjf(process p[],int n){
    int rt[100],wt[100],tat[100],ct[100];
    int completed=0,time=0;

    for(int i=0;i<n;i++){rt[i]=p[i].bt;}
    while(completed<n){
        int smallest=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=time&&rt[i]>0){
                if(smallest==-1||rt[i]<rt[smallest]||rt[i]==rt[smallest]&&p[i].at<p[smallest].at){
                    smallest=i;
                }
            }
        }
        if(smallest==-1){
            time++;
            continue;
        }

        time+=rt[smallest];
        ct[smallest]=time;
        rt[smallest]=0;
        completed++;
    }
}

void srtf(process p[],int n){
    int ct[100],wt[100],tat[100],rt[100];
    int completed=0,time=0;

    for(int i=0;i<n;i++){rt[i]=p[i].bt;}

    while(completed<n){
        int smallest=-1;
            for(int i=0;i<n;i++){
            if(p[i].at<=time&&rt[i]>0){
                if(smallest==-1||rt[i]<rt[smallest]||(rt[i]==rt[smallest]&&p[i].at<p[smallest].at)){
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
                completed++;
                ct[smallest]=time;
            }
    }
}

int main(){
    int n;
    printf("Enter no of processes : ");
    scanf("%d",&n);
    process p[n];
    for(int i=0;i<n;i++){
        printf("Enter Priority,AT,BT : ");
        scanf("%d %d %d",&p[i].pid,&p[i].at,&p[i].bt);
    }
    sort(p,n);
    fcfs(p,n);
}