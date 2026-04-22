/*Given an array of n integers and a key element, write a C program to search the element
using linear search*/
#include<stdio.h>
int main(){
    int arr[10];
    printf("enter no of elements.");
    int n,se,key=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter search element");
    scanf("%d",&se);
    for(int i=0;i<n;i++){
        if(se==arr[i]&&se!=-1)
            key=i;
    }
    if(se==-1)
        printf("element not found");
    else
        printf("%d",key);

}