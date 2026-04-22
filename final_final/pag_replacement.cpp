#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

bool isHit(int e,vector<int>frame){
    for(auto it:frame){
        if(it==e){return true;}
    }
    return false;
}

void display(vector<int>frame,int e,bool isHIT){
    cout<<e<<"\t";
    for(auto it:frame){
        if(it!=-1){
            cout<<it<<" ";
        }
        else{
            cout<<"*"<<" ";
        }
    }
    if(isHIT){cout<<"hit";}
    else{cout<<"Miss";}
    cout<<endl;
}

void fifo(vector<int>s,int fsz){
    vector<int>frame(fsz,-1);
    int hit=0;
    int curr=0;
    for(int i=0;i<s.size();i++){
        if(isHit(s[i],frame)){
            hit++;
            display(frame,s[i],true);
            continue;
        }
        frame[curr]=s[i];
        curr=(curr+1)%fsz;
    display(frame,s[i],false);
    }
}

void optimal(vector<int>s,int fsz){
    vector<int>frame(fsz,-1);
    int hit=0;
    int i=0;
    for( i=0;i<frame.size();i++){
        if(frame[i]==-1){
            frame[i]=s[i];
            display(frame,s[i],false);
        }
    }
    for(;i<s.size();i++){
        if(isHit(s[i],frame)){
            hit++;
            display(frame,s[i],true);
            continue;
        }
        int idx=-1;
        int far=i;
        for(int j=0;j<frame.size();j++){
            int k;
            for(k=i+1;k<s.size();k++){
                if(frame[j]==s[k]){break;}
            }
            if(k>far){
                far=k;
                idx=j;
            }
        }
        frame[idx]=s[i];
        display(frame,s[i],false);
    }
}

void lru(vector<int>s,int fsz){
    vector<int>frame(fsz,-1);
    int hit=0;
    for(int i=0;i<s.size();i++){
        auto it=find(frame.begin(),frame.end(),s[i]);
        if(it!=frame.end()){
            frame.erase(it);
            frame.push_back(s[i]);
            display(frame,s[i],true);
            continue;
        }
        else{
            frame.erase(frame.begin());
            frame.push_back(s[i]);
        }
        display(frame,s[i],false);
    }
}


int main(){
    cout<<"Enter String";
    int x;
    cin>>x;
    vector<int>s;
    while(x!=-1){
        s.push_back(x);
        cin>>x;
    }
    cout<<"Enter frame size:";
    int fsz;
    cin>>fsz;
    //fifo(s,fsz);
    // optimal(s,fsz);
    lru(s,fsz);
}