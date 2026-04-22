#include<iostream>
using namespace std;
#include<cmath>

int main(){
    cout<<"Enter no of pages, page size : ";
    int nop,psz;
    cin>>nop>>psz;
    cout<<"Enter logical address";
    int mem;
    cin>>mem;
    int pno=mem/32;
    int off=mem%32;
    int sz1=log2(nop);
    int sz2=log2(psz);
    cout<<"Size Needed : "<<sz1+sz2<<endl;
    cout<<"Page Number : "<<pno<<endl;
    cout<<"Offset : "<<off<<endl;
}