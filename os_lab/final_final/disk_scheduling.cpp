/*
Lab Exercises:
1. Write a C/C++ Program to simulate the following algorithms find the total no. of cylinder
movements for various input requests
(i) FCFS (ii) SSTF (iii) SCAN (iv) C-SCAN
Additional Exercises:
1. Write a C/C++ Program to simulate the following algorithms find the total no. of cylinder
movements for various input requests
(i) LOOK (ii) C-LOOK
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int disk_size=200;

void fcfs(vector<int>req,int head){
    int cost=0;
    for(int i=0;i<req.size();i++){
        cost+=abs(req[i]-head);
        cout<<head<<"->";
        head=req[i];
    }
}

void sstf(vector<int>req,int head){
    int cost=0;
    vector<bool>vis(req.size(),false);

    for(int i=0;i<req.size();i++){
        int mind=INT_MAX;
        int idx=-1;
        
        for(int j=0;j<req.size();j++){
            if(!vis[j]){
                int diff=abs(req[j]-head);
                if(diff<mind){
                    mind=diff;
                    idx=j;
                }
            }
        }
        cost+=abs(head-req[idx]);
        cout<<head<<"->";
        head=req[idx];
        vis[idx]=true;
    }
}

void scan(vector<int>req,int head){
    int i=0;
    int cost=0;
    sort(req.begin(),req.end());

    while(i<req.size()&&req[i]<head){i++;}
    for(int j=i;j<req.size();j++){
        int dist=abs(req[j]-head);
        cost+=dist;
        cout<<head<<"->";
        head=req[j];
    }
    cost+=abs(disk_size-head);
    cout<<head<<"->"<<disk_size;
    head=disk_size;
    for(int j=i-1;j>=0;j--){
        int dist=abs(head-req[j]);
        cost+=dist;
        cout<<head<<"->";
        head=req[j];
    }
    cout<<cost;
}

void cscan(vector<int>req,int head){
    int i=0;
    int cost=0;
    sort(req.begin(),req.end());

    while(i<req.size()&&req[i]<head){i++;}
    for(int j=i;j<req.size();j++){
        int dist=abs(req[j]-head);
        cost+=dist;
        cout<<head<<"->";
        head=req[j];
    }
    cost+=abs(disk_size-head);
    cout<<head<<"->"<<disk_size;
    head=0;
    for(int j=i-1;j>=0;j--){
        int dist=abs(head-req[j]);
        cost+=dist;
        cout<<head<<"->";
        head=req[j];
    }
    cout<<cost;
}

int main(){
    int n;
    cin>>n;
    vector<int>req;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        req.push_back(x);
    }
}