/*
Write a C/C++ program to simulate First-fit, Best-fit and Worst-fit strategies. Given memory
partitions of 100K, 500K, 200K, 300K, and 600K(in order), how would each of the First-fit,
Best-fit, and Worst-fit algorithms place processes of 212K, 417K, 112K, and 426K (in
order)? Which algorithm makes efficient use of memory?
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

void firstFit(vector<int>partition,vector<int>process){
    for(int i=0;i<process.size();i++){
        for(int j=0;j<partition.size();j++){
            if(process[i]<=partition[j]){
                cout<<process[i]<<"allocated to :"<<partition[j]<<endl;
                partition[j]-=process[i];
                break;
            }
        }    
    }
}

void bestFit(vector<int>partition,vector<int>process){
    for(int i=0;i<process.size();i++){
        int minpart=INT_MAX;
        int idx=-1;
        for(int j=0;j<partition.size();j++){
            if(process[i]<=partition[j]&&partition[j]<minpart){
                minpart=partition[j];
                idx=j;
            }
        }
        if(idx==-1){
            cout<<process[i]<<"allocated to -1"<<endl;
            continue;
        }
        cout<<process[i]<<"allocated to"<<partition[idx]<<endl;
        partition[idx]-=process[i];
        
    }
}

void worstFit(vector<int>partition,vector<int>process){
    for(int i=0;i<process.size();i++){
        int maxpart=INT_MIN;
        int idx=-1;
        for(int j=0;j<partition.size();j++){
            if(process[i]<=partition[j]&&partition[j]>maxpart){
                maxpart=partition[j];
                idx=j;
            }
        }
        if(idx==-1){
            cout<<process[i]<<"allocated to -1";
            continue;
        }
        cout<<process[i]<<"allocated to"<<partition[idx]<<endl;
        partition[idx]-=process[i];
        
    }
}


int main(){
    cout<<"Enter no of ptns, no of procs";
    int nopart,nopro;
    vector<int>partition,process;
    cin>>nopart>>nopro;
    for(int i=0;i<nopart;i++){
        int x;
        cin>>x;
        partition.push_back(x);
    }
    for(int i=0;i<nopro;i++){
        int x;
        cin>>x;
        process.push_back(x);
    }
    firstFit(partition,process);
    bestFit(partition,process);
    worstFit(partition,process);
}