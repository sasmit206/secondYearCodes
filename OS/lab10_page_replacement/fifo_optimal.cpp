#include<iostream>
#include<vector>
using namespace std;

bool isHit(int pg,vector<int>frame){
    for(auto it:frame){
        if(it==pg){return true;}
    }
    return false;
}

void fifo(vector<int>pages,int lof){
    int cur=0;
    int c=0;
    vector<int>frame(lof,-1);
    for(int i=0;i<pages.size();i++){
        if(!isHit(pages[i],frame)){
            frame[cur]=pages[i];
            cur=(cur+1)%lof;
            c++;  
        }
    }
    cout<<"No of misses : "<<c;
}

void optimal(vector<int>pages,int lof){
    int fault=0;
    vector<int>frames(lof,-1);
    for(int i=0;i<pages.size();i++){
        if(isHit(pages[i],frames)){continue;}
        fault++;

        int idx=-1;
        int far=i;
        for(int j=0;j<lof;j++){
            int k=i+1;
            for(;k<pages.size();k++){
                if(pages[k]==frames[j]){
                    break;
                }
            }
            if(k==pages.size()){
                idx=j;
                break;
            }
            if(k>far){
                far=k;
                idx=j;
            }
        }
        if(idx==-1){
            for(int j=0;j<lof;j++){
                if(frames[j]==-1){
                    idx=j;
                    break;
                }
            }
        }
        frames[idx]=pages[i];
        }
        cout<<fault;
    }

int main(){
    int nop,lof;
    vector<int>pages;
    cout<<"enter no of pages";
    cin>>nop;
    cout<<"enter length of frame";
    cin>>lof;
    cout<<"enter the string";
    for(int i=0;i<nop;i++){
        int x;
        cin>>x;
        pages.push_back(x);
    }
    fifo(pages,lof);
}