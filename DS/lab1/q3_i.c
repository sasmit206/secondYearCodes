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
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        printf("%d ,",arr[i]);
    }
    printf("%d .",arr[n-1]);
}