/*
Write a C/C++ program to simulate page replacement algorithms: FIFO and
optimal. Frame allocation has to be done as per user input and use dynamic allocation
for all data structures.
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

bool isHit(int e,vector<int>frame){
    for(auto it:frame){
        if(it==e){return true;}
    }
    return false;
}

void display(vector<int>pages,vector<int>frame,int i){
    cout<<pages[i]<<"\t";
    for(auto it:frame){cout<<it<<" ";}
    cout<<endl;
}

void fifo(vector<int>pages,int fsz){
    int hit=0;
    vector<int>frame(fsz,-1);
    int curr=0;
    for(int i=0;i<pages.size();i++){
        if(isHit(pages[i],frame)){
            display(pages,frame,i);
            hit++;
            continue;
        }
        frame[curr]=pages[i];
        curr=(curr+1)%fsz;
        display(pages,frame,i);
    }
}


void optimal(vector<int>pages,int fsz){
    int hit=0;
    vector<int>frame(fsz,-1);

    for(int i=0;i<pages.size();i++){
        if(isHit(pages[i],frame)){
            hit++;
            display(pages,frame,i);
            continue;
        }


        int far=i;
        int idx=-1;


        bool done=false;
        for(int j=0;j<frame.size();j++){
            if(frame[j]==-1){
                frame[j]=pages[i];
                display(pages,frame,i);
                done=true;
                break;
            }
        }
        if(done){continue;}

        for(int j=0;j<frame.size();j++){
            int k=i+1;
            for(;k<pages.size();k++){
                if(pages[k]==frame[j]){
                    break;
                }
            }
            if(k>far){
                far=k;
                idx=j;
            }
        }
        frame[idx]=pages[i];
    }
}

int main(){
    int pgsz,fsz;
    vector<int>pages;

    cout<<"Enter page size,frame size";
    cin>>pgsz>>fsz;
    for(int i=0;i<pgsz;i++){
        int x;
        cin>>x;
        pages.push_back(x);
    }
    fifo(pages,fsz);
}