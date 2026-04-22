/*Write a C program to sort a given list of elements using
i.) Selection Sort
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
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        int temp=arr[min_index];
        arr[min_index]=arr[i];
        arr[i]=temp;
    }
    printf("the sorted array : \n");
    for(int i=0;i<n;i++)
        printf("%d ,",arr[i]);

}