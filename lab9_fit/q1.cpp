// Write a C/C++ program to simulate First-fit, Best-fit and Worst-fit strategies. Given memory
// partitions of 100K, 500K, 200K, 300K, and 600K(in order), how would each of the First-fit,
// Best-fit, and Worst-fit algorithms place processes of 212K, 417K, 112K, and 426K (in
// order)? Which algorithm makes efficient use of memory?
#include<iostream>
#include<vector>
using namespace std;


void printAlloc(vector<int>&allocation){
    for(int i=0;i<allocation.size();i++){
        cout<<"Process "<<i<<"allocated : "<<allocation[i]<< " " ;
    }
}

void firstFit(vector<int>process,vector<int>block){
    vector<int>allocation(process.size(),-1);
    for(int i=0;i<process.size();i++){
        for(int j=0;j<block.size();j++){
            if(process[i]<=block[j]){
                block[j]=block[j]-process[i];
                allocation[i]=j;
                break;
            }
        }
    }
    printAlloc(allocation);
}

void bestFit(vector<int>process,vector<int>block){
    vector<int>allocation(process.size(),-1);
    for(int i=0;i<process.size();i++){
        int mine=INT_MAX;
        int minidx=-1;
        for(int j=0;j<block.size();j++){
            if(process[i]<=block[j]&&block[j]<mine){
                mine=block[j];
                minidx=j;
            }
        }
        if(minidx==-1){
            allocation[i]=-1;
            continue;
        }
        block[minidx]-=process[i];
        allocation[i]=minidx;
    }
    printAlloc(allocation);
}

void worstFit(vector<int>process,vector<int>block){
    vector<int>allocation(process.size(),-1);
    for(int i=0;i<process.size();i++){
        int maxe=INT_MIN;
        int maxidx=-1;
        for(int j=0;j<block.size();j++){
            if(process[i]<=block[j]&&block[j]>maxe){
                maxe=block[j];
                maxidx=j;
            }
        }
        if(maxidx==-1){
            allocation[i]=-1;
            continue;
        }
        block[maxidx]-=process[i];
        allocation[i]=maxidx;
    }
    printAlloc(allocation);
}

int main(){
    cout<<"Enter no of processes : ";
    int nop;
    cin>>nop;
    vector<int>process(nop);
    cout<<"Enter processes : ";
    for(int i=0;i<nop;i++){cin>>process[i];}

    cout<<"Enter no of blocks : ";
    int nob;
    cin>>nob;
    vector<int>block(nob);
    for(int i=0;i<nob;i++){cin>>block[i];}

    firstFit(process,block);
}