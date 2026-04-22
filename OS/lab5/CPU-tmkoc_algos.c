#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int prior;
    int at;
    int bt;
}process;

void sort(process p[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
                process x=p[j];
                p[j]=p[j+1];
                p[j+1]=x;
            }
        }
    }
}

void fcfs(process p[],int n){
    int wt[100],ct[100],tat[100];
    ct[0]=p[0].at+p[0].bt;
    for(int i=1;i<n;i++){
        ct[i]=(ct[i-1]>p[i].at?ct[i-1]:p[i].at)+p[i].bt;
    }
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-p[i].at;
        wt[i]=tat[i]-p[i].bt;
    }
    printf("FCFS : ");
    printf("\nPRIOR\tAT\tBT\tWT\tTAT\n");
    double atat=0,awt=0;
    for(int i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d\t%d\n",p[i].prior,p[i].at,p[i].bt,wt[i],tat[i]);
        atat+=tat[i];
        awt+=wt[i];
    }
    printf("\n Avg Waiting Time : %.2f \n Avg TAT time : %.2f\n",awt/n,atat/n);
}

void srtf(process p[],int n){
    int wt[100],ct[100],rt[100],tat[100];
    int smallest=-1;
    int time=0,completed=0;

    for(int i=0;i<n;i++){rt[i]=p[i].bt;}

    while(completed<n){
        smallest=-1;
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

    for(int i=0;i<n;i++){
        tat[i]=ct[i]-p[i].at;
        wt[i]=tat[i]-p[i].bt;
    }
    printf("SRTF : ");
    printf("\nP\tAT\tBT\tWT\tTAT\n");
    double atat=0,awt=0;
    for(int i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d\t%d\n",p[i].prior,p[i].at,p[i].bt,wt[i],tat[i]);
        atat+=tat[i];
        awt+=wt[i];
    }
    printf("\n Avg Waiting Time : %.2f \n Avg TAT time : %.2f\n",awt/n,atat/n);
}

void sjf(process p[],int n){
    int tat[100],wt[100],ct[100];
    int time=0,completed=0;
    int rt[100];
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
        time+=rt[smallest];
        rt[smallest]=0;
        ct[smallest]=time;
        completed++;
    }
    
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-p[i].at;
        wt[i]=tat[i]-p[i].bt;
    }
    printf("SJF : ");
    printf("\nP\tAT\tBT\tWT\tTAT\n");
    double atat=0,awt=0;
    for(int i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d\t%d\n",p[i].prior,p[i].at,p[i].bt,wt[i],tat[i]);
        atat+=tat[i];
        awt+=wt[i];
    }
    printf("\n Avg Waiting Time : %.2f \n Avg TAT time : %.2f\n",awt/n,atat/n);
}

void rr(process p[],int n){

}

void priority_np(process p[],int n){
    int ct[100],wt[100],tat[100],rt[100];
    int completed =0,time=0;

    for(int i=0;i<n;i++){rt[i]=p[i].bt;}

    while(completed<n){
        int highest=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=time&&rt[i]>0){
                if(highest==-1||p[i].prior>p[highest].prior||(p[i].prior==p[highest].prior&&p[i].at<p[highest].at)){
                    highest=i;
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

    for(int i=0;i<n;i++){
        tat[i]=ct[i]-p[i].at;
        wt[i]=tat[i]-p[i].bt;
    }
}

void priority_p(process p[],int n){
    int wt[100],ct[100],tat[100],rt[100];
    int completed=0,time=0;
    for(int i=0;i<n;i++){rt[i]=p[i].bt;}


    while(completed<n){
        int highest=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=time&&rt[i]>0){
                if(highest==-1||p[i].prior>p[highest].prior||(p[i].prior==p[highest].prior&&p[i].at<p[highest].at)){
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
            ct[highest]=time;
            completed++;
        }
    }

    for(int i=0;i<n;i++){
        tat[i]=ct[i]-p[i].at;
        wt[i]=tat[i]-p[i].bt;
    }
}


int main(){
    int n;
    printf("Enter no of processes.. ");
    scanf("%d",&n);
    process p[n];
    printf("Enter priority no, AT, BT");
    for(int i=0;i<n;i++){
        printf("Enter details for %d",i+1);
        scanf("%d %d %d",&p[i].prior,&p[i].at,&p[i].bt);
    }
    sort(p,n);
    fcfs(p,n);
    srtf(p,n);
    sjf(p,n);
}