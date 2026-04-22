#include<iostream>
#include<vector>
#define MAX 100
using namespace std;
int nop,nor;

bool banker(int alloc[][MAX],int maxalloc[][MAX],int start[MAX]){
    int work[MAX];
    int need[MAX][MAX];
    for(int i=0;i<nor;i++){
        work[i]=start[i];
    }
    for(int i=0;i<nop;i++){
        for(int j=0;j<nor;j++){
            need[i][j]=maxalloc[i][j]-alloc[i][j];
        }
    }
    vector<bool>vis(nop,false);
    int n=0;
    int safe[nop];

    while(n<nop){
        bool found=false;
        for(int i=0;i<nop;i++){
            if(!vis[i]){
            int j=0;
            for(;j<nor;j++){
                if(need[i][j]>work[j]){break;}
            }
            if(j==nor){
                for(int k=0;k<nor;k++){
                    work[k]+=alloc[i][k];
                }
                safe[n]=i;
                found=true;
                n++;
                vis[i]=true;
                }
            }
        }
        if(!found){
            cout<<"Deadlockk Detected";
            return false;
        }
    }
    for(auto it:safe){cout<<it;}
    cout<<"no deadlock";
    return true;
}

int main(){
    int alloc[MAX][MAX];
    int start[MAX];
    int maxalloc[MAX][MAX];
    cin>>nop>>nor;
    cout<<"Enter max alloc:";
    for(int i=0;i<nop;i++){
        for(int j=0;j<nor;j++){
            cin>>maxalloc[i][j];
        }
    }
    cout<<"Enter alloc";
    for(int i=0;i<nop;i++){
        for(int j=0;j<nor;j++){
            cin>>alloc[i][j];
        }
    }
    cout<<"Enter initial state";
    for(int i=0;i<nor;i++){
        cin>>start[i];
    }
    bool ans=banker(alloc,maxalloc,start);
}