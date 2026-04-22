/*Write a recursive C program to implement Selection Sort using pointers.
• The recursive function should sort the array using the Selection Sort algorithm.
• Access and manipulate the array elements using pointers (i.e., avoid using arr[i]
style directly).
• The program should read the array from the user in the main function, call the
recursive sorting function, and display the sorted array.*/
int* find_min_idx(int* start,int n){
    int* minptr=start;
    for(int* i=start+1;i<start+n;i++){
        if(*(minptr)>*(i))
        {
            minptr=i;
        }
    }
    return minptr;
}
void selection_recur(int* start,int n){
    if(n<=0)
        return;
    int* min = find_min_idx(start,n);
    if(min!=start)
    {
        int temp=*(min);
        *(min)=*(start);
        *(start)=temp;
    }
    selection_recur(start+1,n-1);
}

#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int* arr;
    arr= (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    for(int i=0;i<n;i++){
        printf("%d",*(arr+i));
    }
    selection_recur(arr,n);

    for(int i=0;i<n;i++){
        printf("\n %d ,",*(arr+i));
    }
}