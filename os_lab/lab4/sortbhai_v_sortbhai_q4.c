/*
Write a multithreaded program that performs different sorting algorithms. The
program should work as follows: the user enters on the command line the number
of elements to sort and the elements themselves. The program then creates
separate threads, each using a different sorting algorithm. Each thread sorts the
array using its corresponding algorithm and displays the time taken to produce the
result. The main thread waits for all threads to finish and then displays the final
sorted array.
*/

#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int n;
int arr[100];

void* bubble_thread(void* arg){
    clock_t begin=clock();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    clock_t end=clock();
    printf("\nTime for Bubble Sort = %lfs",(double)(end-begin)/CLOCKS_PER_SEC);
    pthread_exit(NULL);
}

void* selection_thread(void* arg){
    clock_t begin=clock();
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    clock_t end=clock();
    printf("\nTime for Selection Sort = %lfs",(double)(end-begin)/CLOCKS_PER_SEC);
    pthread_exit(NULL);
}

int main(){
    pthread_t t1;
    pthread_t t2;
    arr[0]=2;
    arr[1]=8;
    arr[2]=3;
    arr[3]=89;
    arr[4]=13;
    n=5;
    pthread_create(&t1,NULL,bubble_thread,NULL);
    pthread_create(&t2,NULL,selection_thread,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("\n The Sorted Array : \n");
    for(int i=0;i<n;i++){
            printf("%d , ",arr[i]);
    }

}