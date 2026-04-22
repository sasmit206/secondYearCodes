#include<iostream>
#include<vector>
#define MAX 100
using namespace std;
int nop,nor;

bool isSafe(int alloc[][MAX],int req[][MAX],int start[MAX]){

    vector<bool>vis(nop,false);
    int n=0;
    int safe[nop];

    while(n<nop){
        bool found=false;
        for(int i=0;i<nop;i++){
            if(!vis[i]){
            int j=0;
            for(;j<nor;j++){
                if(req[i][j]>start[j]){break;}
            }
            if(j==nor){
                for(int k=0;k<nor;k++){
                    start[k]+=alloc[i][k];
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
    int req[MAX][MAX];
    cin>>nop>>nor;
    cout<<"Enter req matrix:";
    for(int i=0;i<nop;i++){
        for(int j=0;j<nor;j++){
            cin>>req[i][j];
        }
    }
    cout<<"Enter alloc";
    for(int i=0;i<nop;i++){
        for(int j=0;j<nor;j++){
            cin>>alloc[i][j];
        }
    }
    for(int i=0;i<nor;i++){cin>>start[i];}
    bool ans=isSafe(alloc,req,start);
}