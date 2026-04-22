/*
Implement a C program to read, display, and find the product of two matrices using
functions with appropriate parameters.
• The matrices must be created using dynamic memory allocation (malloc or
calloc).
• Access matrix elements using array dereferencing (i.e., *(*(mat + i) + j)
style)
*/
#include<stdio.h>
#include<stdlib.h>

int** allocate_matrix(int rows,int columns){
    int**arr=(int**)malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++){
        *(arr+i)=(int*)malloc(columns*sizeof(int));
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
        scanf("%d",(*(arr+i)+j));
        }
    }
    return arr;
}
int** multiply_matrices(int** A, int r1, int c1, int** B, int r2, int c2) {
    int** result = (int**)malloc(r1 * sizeof(int*));
    for (int i = 0; i < r1; i++) {
        *(result + i) = (int*)malloc(c2 * sizeof(int));
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            *(*(result + i) + j) = 0;
            for (int k = 0; k < c1; k++) {
                *(*(result + i) + j) += *(*(A + i) + k) * *(*(B + k) + j);
            }
        }
    }

    return result;
}

int main(){
    int r1,c1,r2,c2;
    printf("enter no of rows and columns for 1st matrix : \n ");
    scanf("%d%d",&r1,&c1);
    scanf("%d%d",&r2,&c2);
    int**arr1=allocate_matrix(r1,c1);
    int**arr2=allocate_matrix(r2,c2);
    int**arr3=multiply_matrices(arr1,r1,c1,arr2,r2,c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", *(*(arr3 + i) + j));
        }
        printf("\n");
    }
    
}