#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct process{
    int at;
    int bt;
    int pid;
} process;

void sort(process p[],int n){
    for(int i=0;i<n;i++){
        int temp=i;
        for(int j=i+1;j<n-i-1;j++){
            if(p[j].at>p[temp].at){
                temp=j;
            }
        }
        if(temp!=i){
            process x=p[temp];
            p[temp]=p[i];
            p[i]=x;
        }
    }
}

void fcfs(process p[],int n){
    int ct[100],wt[100],tat[100];
    ct[0]=p[0].at+p[0].bt;
    for(int i=1;i<n;i++){
        ct[i]=((ct[i-1]>p[i].at)?ct[i-1]:p[i].at)+p[i].bt;
    }
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-p[i].at;
        wt[i]=tat[i]-p[i].bt;
    }
    printf("\nFCFS\n");
    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    double awt=0,atat=0;
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,p[i].at,p[i].bt,ct[i],tat[i],wt[i]);
        awt+=wt[i];
        atat+=tat[i];
    }

    printf("Average WT = %f\n",awt/n);
    printf("Average TAT = %f\n",atat/n);
}

void srtf(process p[],int n){
    int tat[1000],wt[1000],ct[1000],rt[1000];
    int smallest=-1,time=0,completed=0;
    for(int i=0;i<n;i++){
        rt[i]=p[i].bt;
    }

    while(completed<n){
        smallest=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=time && rt[i]>0){
                if(smallest==-1||rt[i]<rt[smallest]||(rt[i]==rt[smallest])&&p[i].at<p[smallest].at){
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

    printf("SRTF\n");
    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-p[i].at;
        wt[i]=tat[i]-p[i].bt;
    }
    double awt=0,atat=0;
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,p[i].at,p[i].bt,ct[i],tat[i],wt[i]);
        awt+=wt[i];
        atat+=tat[i];
    }

    printf("Average WT = %f\n",awt/n);
    printf("Average TAT = %f\n",atat/n);

}

void sjf(process p[],int n){
    int wt[100],ct[100],rt[100],tat[100];
    int smallest=-1,completed=0,time=0;
    while(completed<n){
        for(int i=0;i<n;i++){
            if(p[i].at>time||rt[i]>0){
                if(completed==-1||rt[i]<rt[smallest]||(rt[i]=rt[smallest]&&p[i].at<p[smallest].at))
                    smallest=i;
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

void priority_p(process p[],int n){
    
    int completed=0;
    int time=0;
    int rt[100],ct[100],wt[100],tat[100];
    
    for(int i=0;i<n;i++){
        rt[i]=p[i].bt;
    }

    while(completed<n){
        int highest=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<time&&rt[i]>0){
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
    double awt=0,atat=0;
    for(int i=0;i<n;i++){
        tat[i] = ct[i] - p[i].at;
        wt[i] = tat[i] - p[i].bt;
        awt += wt[i];
        atat += tat[i];
    }

    // Output
    printf("\nPriority Preemptive\n");
    printf("P\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,p[i].at,p[i].bt,p[i].pid,ct[i],tat[i],wt[i]);
    }

    printf("Average WT = %.2f\n", awt/n);
    printf("Average TAT = %.2f\n", atat/n);
}

void priority_np(process p[],int n){
    int rt[100],wt[100],tat[100],ct[100];
    int completed=0,time=0;
    for(int i=0;i<n;i++){
        rt[i]=p[i].bt;
    }

    while(completed<n){
        int highest=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=time && rt[i]>0){
                    if(highest==-1||p[i].pid>p[highest].pid||(p[i].pid==p[highest].pid&&p[i].at<p[highest].at)){
                        highest=i;
                    }
            }
        }

        if(highest==-1){
            time++;
            continue;
        }

        time+=rt[highest];
        ct[highest]=time;
        rt[highest]=0;
        completed++;
    }
    double awt=0,atat=0;
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-p[i].at;
        wt[i]=tat[i]-p[i].bt;
        awt += wt[i];
        atat += tat[i];

    }

    printf("\nPriority Non-Preemptive\n");
    printf("P\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,p[i].at,p[i].bt,p[i].pid,ct[i],tat[i],wt[i]);
    }

    printf("Average WT = %.2f\n", awt/n);
    printf("Average TAT = %.2f\n", atat/n);

}

void rr(process p[],int n){
    int ct[100],wt[100],rt[100];
    int completed=0;
    double atat=0,awt=0,time=0;

    for(int i=0;i<n;i++){rt[i]=p[i].bt;}

    printf("Enter Time Quantum : ");
    int tq;
    scanf("%d",&tq);
    while(completed<n){
        int flag=0;
        for(int i=0;i<n;i++){
            if(p[i].at<=time&&rt[i]>0){
                flag=1;
                if(rt[i]<tq){
                    time+=rt[i];
                    rt[i]=0;
                    ct[i]=time;
                    completed++;
                }
                else{
                    time+=tq;
                    rt[i]-=tq;
                }
            }
            if(flag==0){
                time++;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter no of processes");
    scanf("%d",&n);
    process *p=malloc(n*sizeof(process));
    for(int i=0;i<n;i++){
        scanf("%d",&p[i].at);
        scanf("%d",&p[i].bt);
        scanf("%d",&p[i].pid);
    }
    sort(p,n);
    for(int i=0;i<n;i++){
        printf("%d",p[i].at);
        printf("%d",p[i].bt);
        printf("%d",p[i].pid);
    }
    fcfs(p,n);
    srtf(p,n);
    sjf(p,n);
    priority_p(p,n);
    priority_np(p,n);
}