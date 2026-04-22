#include<iostream>
#include<vector>
using namespace std;

void fcfs(vector<int>req,int head){
    int mvmt=0;
    for(int i=0;i<req.size();i++){
        mvmt+=abs(req[i]-head);
        head=req[i];
    }
    cout<<mvmt;
}

void sstf(vector<int>req,int head){
    int mvmt=0;
    vector<bool>vis(req.size(),false);
    for(int i=0;i<req.size();i++){
        int idx=-1;
        int mind=INT_MAX;
        for(int j=0;j<req.size();j++){
            if(!vis[j]){
                int dist=abs(head-req[j]);
                if(dist<mind){
                    mind=dist;
                    idx=j;
                }
            }
        }
        vis[idx]=true;
        mvmt+=abs(head-req[idx]);
        head=req[idx];
    }
    cout<<mvmt;
}

void scan(vector<int>req,int head){

    sort(req.begin(),req.end());
    int dick_size=*max_element(req.begin(),req.end());
    //assuming dirn right pe ja rha hai
    int i=0;
    while(i<req.size()&&req[i]<head){
        i++;
    }
    int mvmt=0;
    for(int j=i;j<req.size();j++){
        mvmt+=abs(head-req[j]);
        head=req[j];
    }
    mvmt+=abs(dick_size-head);
    head=dick_size;
    for(int j=i-1;j>=0;j--){
        mvmt+=abs(head-req[j]);
        head=req[j];
    }
    cout<<mvmt;

}


void cscan(vector<int>req,int head){

    sort(req.begin(),req.end());
    int dick_size=*max_element(req.begin(),req.end());//ik max size should be from user
    //assuming dirn right pe ja rha hai
    int i=0;
    while(i<req.size()&&req[i]<head){
        i++;
    }
    int mvmt=0;
    for(int j=i;j<req.size();j++){
        mvmt+=abs(head-req[j]);
        head=req[j];
    }
    mvmt+=abs(dick_size-head);
    head=0;
    for(int j=0;j<i;j++){
        mvmt+=abs(head-req[j]);
        head=req[j];
    }
    cout<<mvmt;

}


int main(){
    vector<int>req;
    cout<<"Enter no of req.";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        req.push_back(x);
    }
    cout<<"Enter value of head";
    int head;
    cin>>head;
    fcfs(req,head);
}