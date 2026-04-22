#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

bool isHit(int e,vector<int>pages){
    for(auto it:pages){
        if(it==e){return true;}
    }
    return false;
}

void display(vector<int>pages,vector<int>frame,int i){
    cout<<pages[i]<<"\t";
    for(int i=0;i<frame.size();i++){
        if(frame[i]!=-1){
            cout<<frame[i]<<" ";
        }
        else
            cout<<"_"<<" ";
    }
    cout<<endl;
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
                if(pages[k]==frame[j]){break;}
            }
            if(k>far){
                far=k;
                idx=j;
            }
        }
        frame[idx]=pages[i];
        display(pages,frame,i);
    }
}

int main(){
    vector<int>pages;
    int pgsz,fsz;
    cout<<"Enter Page Size, Frame Size. :";
    cin>>pgsz>>fsz;
    cout<<"Enter Pages";
    for(int i=0;i<pgsz;i++){
        int x;
        cin>>x;
        pages.push_back(x);
    }
    optimal(pages,fsz);
}