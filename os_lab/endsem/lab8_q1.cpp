//Dedlock

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int nop,nor;

bool isSafe(int max[][10],int alloc[][10],int start[10]){
    int need[nop][nor];
    int finish[10]={0};

    for(int i=0;i<nop;i++){
        for(int j=0;j<nor;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    int work[10];
    for(int i=0;i<nor;i++){work[i]=start[i];}

    int n=0;

    while(n<nop){
        bool found=false;
        for(int i=0;i<nop;i++){
            if(!finish[i]){
                int j=0;
                for(j=0;j<nor;j++){
                    if(need[i][j]>work[j]){break;}
                }
                if(j==nor){
                    for(int k=0;k<nor;k++){
                        work[k]+=alloc[i][k];
                    }
                    finish[i]=1;
                    n++;
                    found=true;
                }
            }
            
        }
        if(found==false){
            cout<<"Deadlock";
            return false;
        }
    }
    return true;
}

int main(){
    cout<<"Enter no of processes, No. of Resource Types:";
    
    cin>>nop>>nor;
    int alloc[nop][nor];
    int max[nop][nor];
    int start[nor];

    cout<<"Enter Max Allocation Matrix: ";
    for(int i=0;i<nop;i++){
        for(int j=0;j<nor;j++){
            cin>>max[i][j];
        }
    }

    cout<<"Enter Allocation Matrix: ";
    for(int i=0;i<nop;i++){
        for(int j=0;j<nor;j++){
            cin>>alloc[i][j];
        }
    }
    
    
    cout<<"Enter Initial Resources: ";
    for(int i=0;i<nor;i++){
        cin>>start[i];
    }

    bool ans= isSafe(max,alloc,start);
    cout<<ans;
}