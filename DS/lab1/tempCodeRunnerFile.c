/*Write a C program to sort a given list of elements using
i.) Bubble Sort
*/
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
    n=sizeof(arr)/sizeof(arr[0]);