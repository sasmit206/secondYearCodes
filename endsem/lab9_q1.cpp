/*
Write a C/C++ program to simulate First-fit, Best-fit and Worst-fit strategies. Given memory
partitions of 100K, 500K, 200K, 300K, and 600K(in order), how would each of the First-fit,
Best-fit, and Worst-fit algorithms place processes of 212K, 417K, 112K, and 426K (in
order)? Which algorithm makes efficient use of memory?
*/

#include<iostream>
#include<vector>
using namespace std;

void display(vector<int>allocation){
    cout<<"The Allocation is\n";
    for(int i=0;i<allocation.size();i++){
        cout<<i<<"->"<<allocation[i]<<endl;
    }
}

void firstFit(vector<int>m,vector<int>p){
    vector<int>allocation(p.size(),-1);
    for(int i=0;i<p.size();i++){
        int fidx=-1;
        for(int j=0;j<m.size();j++){
            if(p[i]<=m[j]){
                m[j]=m[j]-p[i];
                fidx=j;
                break;
            }
        }
        allocation[i]=fidx;
    }
    display(allocation);
}

void bestFit(vector<int>m,vector<int>p){
    vector<int>allocation(p.size(),-1);

    for(int i=0;i<p.size();i++){
        int fidx=-1;
        int minM=INT_MAX;
        for(int j=0;j<m.size();j++){
            if(p[i]<=m[j]&&m[j]<minM){
                minM=m[j];
                fidx=j;
            }
        }
        if(fidx!=-1){m[fidx]-=p[i];}
        allocation[i]=fidx;
    }
    display(allocation);
}

void worstFit(vector<int>m,vector<int>p){
    vector<int>allocation(p.size(),-1);

    for(int i=0;i<p.size();i++){
        int fidx=-1;
        int maxM=INT_MIN;
        for(int j=0;j<m.size();j++){
            if(p[i]<=m[j]&&m[j]>maxM){
                maxM=m[j];
                fidx=j;
            }
        }
        if(fidx!=-1){m[fidx]-=p[i];}
        allocation[i]=fidx;
    }
    display(allocation);
}

int main(){
    int n;
    vector<int>m;
    cout<<"Enter No of Memory Blocks:\n";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter Memmory Block  : "<<i+1<<" ";
        int x;
        cin>>x;
        m.push_back(x);
    }

    vector<int>p;
    cout<<"Enter No of Processes:\n";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter Process :"<<i+1<<" ";
        int x;
        cin>>x;
        p.push_back(x);
    }

    firstFit(m,p);
    bestFit(m,p);
    worstFit(m,p);
}