/*  Write a small function to find the smallest element in an array using pointers.
In the main function, create a dynamically allocated array, read the values from the
keyboard, and pass the array to the function.
Display the result (smallest element) in the main function.*/
#include<stdio.h>
#include<stdlib.h>
int smallest(int* arr,int n){
    int min=*(arr);
    for(int i=1;i<n;i++){
        if(min>*(arr+i))
            min=*(arr+i);
    }
    return min;
}
int main(){
    int* arr;
    int n;
    scanf("%d",&n);
    arr= (int*)(malloc(n*sizeof(int)));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("the dynamically allocated array : \n");
    for(int i=0;i<n;i++){
        printf("%d ,",arr[i]);
    }
    int small = smallest(arr,n);
    printf("\nthe smallest element is : %d",small);
}