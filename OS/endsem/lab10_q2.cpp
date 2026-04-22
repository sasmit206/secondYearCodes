#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printFrame(vector<int>frame,int sz){
    for(int i=0;i<sz;i++){
        if(i<frame.size()){
            cout<<frame[i];
        }
        else{
            cout<<"_";
        }
    }
    cout<<endl;
}

void lru(vector<int>s,int sz){
    vector<int>frame;
    for(int i=0;i<s.size();i++){
        auto it=find(frame.begin(),frame.end(),s[i]);
        if(it!=frame.end()){
            frame.erase(it);
            frame.push_back(s[i]);
        }
        else{
            if(frame.size()==sz){
                frame.erase(frame.begin());
            }
            frame.push_back(s[i]);
        }
        printFrame(frame,sz);
    }
}

int main(){
    cout<<"Enter Length of String";
    int n;
    cin>>n;
    vector<int>s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.push_back(x);
    }
    cout<<"Enter Capacity of Frame";
    int sz;
    cin>>sz;
    lru(s,sz);
}