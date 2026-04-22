#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define MAX 100

int nop,nor;

bool dead_detect(int alloc[][MAX],int req[][MAX],int start[MAX]){
    int n=0;
    int work[MAX];
    for(int i=0;i<nor;i++){work[i]=start[i];}
    vector<bool>vis(nop,false);

    while(n<nop){
        bool found=false;
        for(int i=0;i<nop;i++){
            if(!vis[i]){
                int j=0;
                for(;j<nor;j++){
                    if(work[j]<req[i][j]){break;}
                }
                if(j==nor){
                    found=true;
                    for(int k=0;k<nor;k++){work[k]+=alloc[i][k];}
                    vis[i]=true;
                    n++;
                }
            }
        }
        if(!found){return false;}
    }
    return true;
}


int main(){
    cout<<"Enter no of process, no of resources";
    cin>>nop>>nor;
    int alloc[MAX][MAX];
    int req[MAX][MAX];
    for(int i=0;i<nop;i++){
        for(int j=0;j<nor;j++){
            cin>>alloc[i][j];
        }
    }
    for(int i=0;i<nop;i++){
        for(int j=0;j<nor;j++){
            cin>>req[i][j];
        }
    }
    int start[nor];
    for(int i=0;i<nor;i++){
        cin>>start[i];
    }
    bool ans=dead_detect(alloc,req,start);
    
}