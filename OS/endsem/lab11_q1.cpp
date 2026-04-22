#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int diks_size=200;

void fcfs(vector<int>req,int head){
    int cost=0;
    for(int i=0;i<req.size();i++){
        cout<<head<<"->";
        cost+=abs(head-req[i]);
        head=req[i];
    }
    cout<<endl;
    cout<<"FCFS Cost:"<<cost<<endl;
}

void sstf(vector<int>req,int head){
    int cost=0;
    vector<bool>vis(req.size(),false);
    for(int i=0;i<req.size();i++){
        int min_d=INT_MAX;
        int idx=-1;
        for(int j=0;j<req.size();j++){
            if(!vis[j]){
                int dist=abs(req[j]-head);
                if(dist<min_d){
                    min_d=dist;
                    idx=j;
                }
            }
        }
        vis[idx]=true;
        cost+=abs(head-req[idx]);
        cout<<head<<"->";
        head=req[idx];
    }
    cout<<"Cost of SSTF:"<<cost;
}

void scan(vector<int>req,int head){
    sort(req.begin(),req.end());
    int i=0;
    while(i<req.size()&&req[i]<head){
        i++;
    }
    int cost=0;

    for(int j=i-1;j>=0;j--){
        cost+=abs(req[j]-head);
        cout<<head<<"->";
        head=req[j];
    }

    cost+=abs(head-0);
    head=0;

    for(int j=i;j<req.size();j++){
        cost+=abs(head-req[j]);
        cout<<head<<"->";
        head=req[j];
    }
    
    cout<<endl;
    cout<<cost;
}

void cscan(vector<int>req,int head){
    sort(req.begin(),req.end());
    int i=0;
    while(i<req.size()&&req[i]<head){
        i++;
    }
    int cost=0;

    for(int j=i;j<req.size();j++){
        cost+=abs(head-req[j]);
        cout<<head<<"->";
        head=req[j];
    }
    cout<<"->"<<diks_size;

    cost+=abs(head-diks_size);
    head=0;
    cout<<"0->";

    for(int j=0;j<i;j++){
        cost+=abs(req[j]-head);
        cout<<head<<"->";
        head=req[j];
    }
    
    cout<<endl;
    cout<<cost;
}

int main(){
    // vector<int>req;
    // int n;
    // int head;
    // cout<<"Enter no of req";
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     req.push_back(x);
    // }
    // cout<<"Enter Head:";
    // cin>>head;

    int head = 53;
    vector<int> req = {37, 14, 65, 67, 98, 122, 124, 183}; 
    // fcfs(req,head); 
    // sstf(req,head);
    // scan(req,head);
    cscan(req,head);
}