/*Given an array of integers, implement binary search to find the position of a given key.*/
#include<stdio.h>
int main(){
    int n;
    printf("enter no of elements");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements in array : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int l=0,r=n-1;
    int m,key;
    int flag=0;
    printf("enter search element");
    scanf("%d",&key);
    while(l<=r){
        m=l+(r-l)/2;
        if(arr[m]==key){
            printf("%d search element found at index %d",key,m);
            flag=1;
            break;
        }
        if(key>arr[m])
            l=m+1;
        if(key<arr[m])
            r=m-1;
    }
    if(flag==0)
        printf("search element not found");
}