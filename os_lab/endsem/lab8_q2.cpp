#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int nop,nor;

bool isDeadlock(int alloc[][10],int req[][10],int start[10]){
    int work[nor];

    for(int i=0;i<nor;i++){
        work[i]=start[i];
    }   

    int safe[nop];
    int finish[10]={0};
    int n=0;
    while(n<nop){
        bool found=true;
        for(int i=0;i<nop;i++){
            int j=0;
            if(!finish[i]){
                for(;j<nor;j++){
                    if(req[i][j]>work[j]){break;}
                }
                if(j==nor){
                    for(int k=0;k<nor;k++){
                        work[k]+=alloc[i][k];
                    }
                    finish[i]=1;
                    safe[n++]=i;
                    found=false;

                }
            }
        }
        if(found==true){
            cout<<"Deadlock present";
            return true;
        }
    }
    return false;

}

int main(){
    cout<<"Enter no of processes, no of resources";
    
    cin>>nop>>nor;
    int alloc[10][10];
    int req[10][10];
    int start[10];

    cout<<"Enter Allocation Matrix: ";
    for(int i=0;i<nop;i++){
        for(int j=0;j<nor;j++){
            cin>>alloc[i][j];
        }
    }

    cout<<"Enter Request Matrix: ";
    for(int i=0;i<nop;i++){
        for(int j=0;j<nor;j++){
            cin>>req[i][j];
        }
    }

    cout<<"Enter initial state:";
    for(int i=0;i<nor;i++){
        cin>>start[i];
    }
    bool ans= isDeadlock(alloc,req,start);
    cout<<ans;
}