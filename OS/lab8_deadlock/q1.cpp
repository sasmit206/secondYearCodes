#include<iostream>
using namespace std;

int n,m;

bool isSafe(int avl[],int max[][10],int alloc[][10]){
    int need[10][10],work[10],safe[10],finish[10]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(int i=0;i<m;i++){work[i]=avl[i];}
    int nop=0;

    while(nop<n){
        bool found=false;
        for(int i=0;i<n;i++){
            if(!finish[i]){
                int j;
                for(j=0;j<m;j++){
                    if(need[i][j]>work[j]){break;}
                }
                if(j==m){
                    for(int k=0;k<n;i++){work[i]+=alloc[i][j];}
                    finish[i]=1;
                    safe[nop++]=i;
                    found=true;
                }
            }
        }
        if(found==false){
            cout<<"Deadlock encountered";
            return false;
        }
    }
}
int main(){
    
    cout<<"Enter no. of processes, no of resource types: ";
    cin>>n>>m;
    cout<<"\nEnter current Available resources: ";
    int avl[m];
    int alloc[n][m];
    int max[n][m];
    for(int i=0;i<m;i++){
        cin>>avl[i];
    }
    cout<<"Enter Max Allocation Matrix : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>max[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>alloc[i][j];
        }
    }
    isSafe(avl,max,alloc);
}