/*Write a C program to sort a given list of elements using
iii.) Insertion Sort*/
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        int j=i;
        while(j>0&&arr[j-1]>arr[j]){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
    printf("the sorted array is : \n");
    for(int i=0;i<n;i++){
        printf("%d ,",arr[i]);
    }

}