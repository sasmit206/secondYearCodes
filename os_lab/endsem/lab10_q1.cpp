//implementing Fifo,Optimal
#include<iostream>
#include<vector>
using namespace std;


bool isPresent(int num,vector<int>frame){
    for(auto it:frame){
        if(num==it){
            return true;
        }
    }
    return false;
}

void fifo(vector<int>v,int lof){
    int miss=0;
    int curr=0;
    vector<int>frame(lof,-1);
    for(int i=0;i<v.size();i++){
        if(!isPresent(v[i],frame)){
            miss++;
            frame[curr]=v[i];
            curr=(curr+1)%lof;
        }
        for(auto it:frame){cout<<it;}
    }
}

void optimal(vector<int>v,int lof){
    vector<int>frame(lof,-1);
    vector<int>allocation(v.size());
    int miss=0;

    for(int i=0;i<v.size();i++){
        if(isPresent(v[i],frame)){
            continue;
        }
        miss++;
        int idx=-1;
        int far=i;
        for(int j=0;j<frame.size();j++){
            if(frame[j]==-1){
                idx=j;
            }
        }

        if(idx==-1){
            for(int j=0;j<frame.size();j++){
                int k=i+1;
                for(;k<v.size();k++){
                    if(frame[j]==v[k]){
                        break;
                    }
                }
                if(k>far){
                    far=k;
                    idx=j;
                }
            }
        }   
        allocation[i]=idx;
    }
}

int main(){
    int los,lof;
    vector<int>v;
    cout<<"Enter length of string: ";
    cin>>los;
    for(int i=0;i<los;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter length of frame: ";
    cin>>lof;

    fifo(v,lof);


}