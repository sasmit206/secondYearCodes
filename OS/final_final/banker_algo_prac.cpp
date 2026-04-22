#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#define MAX 100
using namespace std;

int nor,nop;

bool banker(int alloc[][MAX],int maxa[][MAX],int start[MAX]){
    int need[MAX][MAX];
    for(int i=0;i<nop;i++){
        for(int j=0;j<nor;j++){
            need[i][j]=maxa[i][j]-alloc[i][j];
        }
    }

    int work[MAX];
    for(int i=0;i<nor;i++){
        work[i]=start[i];
    }
    int count=0;
    vector<bool>vis(nop);
    int safe[nop];


    while(count<nop){
        bool found=false;
        for(int i=0;i<nop;i++){
            if(!vis[i])
            {
                int j=0;
                for(;j<nor;j++){
                    if(need[i][j]>work[j]){break;}
                }
                if(j==nor){
                    for(int k=0;k<nor;k++){work[k]+=alloc[i][k];}
                    found=true;
                    safe[count++]=i;
                    vis[i]=true;
                }
            }
        }
        if(!found){return false;}
    }
    for(auto it:safe){cout<<it;}
    return true;

}




int main(){
    
    cout<<"Enter no of process and no of resources : ";
    cin>>nop>>nor;
    int maxa[MAX][MAX];
    int alloc[MAX][MAX];
    int start[MAX];
    for(int i=0;i<nop;i++){
        for(int j=0;j<nor;j++){
            cin>>maxa[i][j];
        }
    }
    for(int i=0;i<nop;i++){
        for(int j=0;j<nor;j++){
            cin>>alloc[i][j];
        }
    }
    cout<<"Enter initial state:";
    for(int i=0;i<nor;i++){
        cin>>start[i];
    }
    banker(alloc,maxa,start);

}