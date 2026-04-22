#include<iostream>
#include<vector>
using namespace std;
#define MAX 100 
vector<int>process;
vector<int>block;
vector<int>allocation;
int n;
void printResult(vector<int>&allocation){
    cout<<endl<<endl;
    for(int i=0;i<allocation.size();i++){
        cout<<"Process "<<i+1;
        if(allocation[i]==-1){
            cout<<"Not allocated T-T"<<endl;
            continue;
        }
        cout<<"allocated : "<<allocation[i]<<endl;
    }
}
void firstFit(vector<int>&process,vector<int>block){
    vector<int>allocation(process.size(),-1);
    for(int i=0;i<process.size();i++){
        for(int j=0;j<block.size();j++){
            if(process[i]<=block[j]){
                block[j]-=process[i];
                allocation[i]=j;
                break;
            }
        }
    }
    printResult(allocation);
}

void bestFit(vector<int>&process,vector<int>block){
    vector<int>allocation(process.size(),-1);
    for(int i=0;i<process.size();i++){
        int bidx=-1;
        for(int j=0;j<block.size();j++){
            if(process[i]<=block[j]){
                if(bidx==-1 || block[j]<block[bidx]){
                    bidx=j;
                }
            }
        }
        if(bidx!=-1){
            allocation[i]=bidx;
            block[bidx]-=process[i];
        }
    }
    printResult(allocation);
}

void worstFit(vector<int>&process,vector<int>block){
    vector<int>allocation(process.size(),-1);
    for(int i=0;i<process.size();i++){
        int widx=-1;
        for(int j=0;j<block.size();j++){
            if(process[i]<=block[j]){
                if(widx==-1||block[j]>block[widx]){
                    widx=j;
                }
            }
        }
        if(widx!=-1){
            allocation[i]=widx;
            block[widx]-=process[i];
        }        
    }
    printResult(allocation);
}

int main(){
    // cout<<"Enter no of processes";
    // int n;
    // cin>>n;
    
    // for(int i=0;i<n;i++){
    //     int x;
    //     cout<<"Enter value of process"<<i<<" : ";
    //     cin>>x;
    //     process.push_back(x);
    // }  
    
    vector<int> block = {100, 500, 200, 300, 600};
    vector<int> process = {212, 417, 112, 426};
    n=process.size();
    firstFit(process,block);
    worstFit(process,block);
    bestFit(process,block);
}