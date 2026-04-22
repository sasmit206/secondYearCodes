#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
#define MAX 100
int nop,nor;

bool banker(int alloc[][MAX],int maxa[][MAX],int start[MAX]){
    int need[MAX][MAX];
    for(int i=0;i<nop;i++){
        for(int j=0;j<nor;j++){
            need[i][j]=maxa[i][j]-alloc[i][j];
        }
    }
    int work[MAX];
    for(int i=0;i<nor;i++){work[i]=start[i];}
    int n=0;
    vector<bool>vis(nop,false);
    int safe[MAX];
    int count=0;
    bool found;
    
    while(count<nop){
    found=false;
        for(int i=0;i<nop;i++){
            if(!vis[i]){
                int j;
                for(j=0;j<nor;j++){
                    if(need[i][j]>work[j]){break;}
                }
                if(j==nor){
                    for(int k=0;k<nor;k++){
                        work[k]+=alloc[i][k];   
                    }
                    vis[i]=true;
                    safe[count++]=i;
                    found=true;
                }
            }
        }
        if(!found){return false;}
    }
    
    for(int i=0;i<nop;i++){
        cout<<safe[i];
    }
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