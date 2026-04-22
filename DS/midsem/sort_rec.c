#include<stdio.h>
void rec_sel(int* arr, int start, int n){
    if(start>=n){return;}
    int min_idx=start;
    for(int j=start;j<n;j++){
        if(arr[j]<arr[min_idx]){
            min_idx=j;
        }
    }
    if(min_idx!=start){
        int temp=arr[start];
        arr[start]=arr[min_idx];
        arr[min_idx]=temp;
    }
    rec_sel(arr,start+1,n-1);
}
void rec_ins(int* arr, int n){
    if(n<=1){return;}
    rec_ins(arr,n-1);
    int key=arr[n-1];
    int j=n-2;
    while(j>0&&arr[j]>key){
        arr[j+1]=key;
    }
    arr[j+1]=key;

}

void rec_bub(int*arr,int n){
    if(n<=1){return;}
    for(int j=0;j<n-1;j++){
        if(arr[j+1]<arr[j]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
    rec_bub(arr,n-1);
}

void rec_sel2(int*arr,int start,int n){
    int min_idx=start;
    if(start==n){return;}
    for(int j=start;j<n;j++){
        if(arr[j]<arr[min_idx])
            min_idx=j;
    }
    if(min_idx!=start){
        int temp=*(arr+start);
        *(arr+start)=*(arr+min_idx);
        *(arr+min_idx)=temp;
    }
    rec_sel2(arr,start+1,n);
}

void rec_ins2(int* arr,int i , int n){
    if(n<=1){return;}
    rec_ins2(arr,i,n-1);
    int key=arr[n-1];
    int j=n-2;
    while(j>0&&arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}
int main(){
    int arr[]={2,3,4,12,7,-3};
    //rec_sel(arr,0,7);
    //rec_sel2(arr,0,6);
    rec_ins2(arr,0,6);
    for(int i=0;i<6;i++){
        printf("%d , ",*(arr+i));
    }

}