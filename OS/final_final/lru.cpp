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

void lru(vector<int>pages,int fsz){
    vector<int>frame;
    int hit=0;

    for(int i=0;i<pages.size();i++){
        auto it=find(frame.begin(),frame.end(),pages[i]);
        if(it!=frame.end()){
            frame.erase(it);
            frame.push_back(pages[i]);
            display(pages,frame,i);
            continue;
        }
        else{
            if(frame.size()==fsz){
                frame.erase(frame.begin());
            }
            frame.push_back(pages[i]);
        }
    display(pages,frame,i);
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
    lru(pages,fsz);
}