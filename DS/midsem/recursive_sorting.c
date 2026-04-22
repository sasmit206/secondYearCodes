#include<stdio.h>
void rec_bubble_sort(int arr[],int n){
    if(n<1){return;}
    for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    rec_bubble_sort(arr,n-1);
}

void rec_sel_sort(int arr[],int start, int n){
    if(start >= n){return ;}
    int min_idx=start;
    for(int i=start;i<n;i++){
        if(arr[i]<arr[min_idx]){min_idx=i;}
    }
    if(min_idx!=start){
        int temp=arr[min_idx];
        arr[min_idx]=arr[start];
        arr[start]=temp;
    }
    rec_sel_sort(arr,start+1,n);
}

void rec_ins_sort(int arr[],int n){
    if(n<=1){return;}
    rec_ins_sort(arr,n-1);
    int key=arr[n-1];
    int j=n-2;
    while(j>=0&&arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;


}
int main(){
    int n;
    int arr[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    rec_ins_sort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}