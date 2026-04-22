/*
Write a C/C++ program to simulate First-fit, Best-fit and Worst-fit strategies. Given memory
partitions of 100K, 500K, 200K, 300K, and 600K(in order), how would each of the First-fit,
Best-fit, and Worst-fit algorithms place processes of 212K, 417K, 112K, and 426K (in
order)? Which algorithm makes efficient use of memory?
*/

#include<iostream>
#include<vector>
using namespace std;

void firstFit(vector<int>pages,vector<int>process){
    for(int i=0;i<process.size();i++){
        for(int j=0;j<pages.size();j++){
            if(process[i]<=pages[j]){
                cout<<process[i]<<"allocated to :"<<pages[j];
                pages[j]-=process[i];
                break;
            }
        }
    }
}

void bestFit(vector<int>pages,vector<int>process){
    for(int i=0;i<process.size();i++){
        int minP=INT_MAX;
        int idx=-1;
        for(int j=0;j<pages.size();j++){
            if(process[i]<=pages[j]&&pages[j]<minP){
                minP=pages[j];
                idx=j;
            }
        }
        if(idx==-1){
            cout<<"nahi mila";
            continue;
        }
        cout<<"Process"<<process[i]<<"Allocated to :"<<pages[idx];
    }
}

void worstFIt(vector<int>pages,vector<int>process){
    for(int i=0;i<process.size();i++){
        int maxP=INT_MIN;
        int idx=-1;
        for(int j=0;j<pages.size();j++){
            if(process[i]<=pages[j]&&pages[j]>maxP){
                maxP=pages[j];
                idx=j;
                // pages[j]-=process[i];
            }
        }
        // if(idx==-1){
        //     cout<<"nahi mila";
        //     continue;
        // }
        cout<<"Process"<<process[i]<<"Allocated to :"<<pages[idx];
    }
}


int main(){
    vector<int>pages,process;
    cout<<"Enter no of pages, no of process:";
    int pgno,nop;
    cin>>pgno>>nop;
    while(pgno--){
        int x;
        cin>>x;
        pages.push_back(x);
    }
    while(nop--){
        int x;
        cin>>x;
        process.push_back(x);
    }
    firstFit(pages,process);
}