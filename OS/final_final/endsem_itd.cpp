// implement LSTF (Largest Seek Time First) disk scheduling along with MFU (Most Frequently Used) page replacement.

// Input:

// Number of frames
// Initial head position
// Pairs of (page number, cylinder position) until user enters -1

// Task:

// First, apply LSTF disk scheduling on the given input.
// Using the resulting order, generate the page request sequence.
// Apply MFU page replacement on the generated sequence and display the results.

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


void lstf(vector<int>req,int head){
    vector<bool>vis(req.size(),false);
    for(int i=0;i<req.size();i++){
        int maxd=INT_MIN;
        int idx=-1;
        for(int j=0;j<req.size();j++){
            if(!vis[j]){
                int dist=abs(head-req[j]);
                if(dist>maxd){
                    maxd=dist;
                    idx=j;
                }
            }
        }
        vis[idx]=true;
        cout<<head<<"->";
        head=req[idx];
    }
}

int main(){
    int n;
    cin>>n;
    int head;
    cin>>head;
    vector<int>req;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        req.push_back(x);
    }
    lstf(req,head);
}