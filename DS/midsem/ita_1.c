/*
Q1
Program with structure and pointers title 
structure of books-
each book has title, author and price
sort based on price recursively using insertion sort using pointer arithmetic 
display after sorting
*/

#include<stdio.h>
typedef struct book
{
    char title[100];
    char author[100];
    int p;
}book;

void rec_ins_sort(book *b,int i, int n){
    if(i==n){return;}
    book key= *(b+i);
    int j=i-1;
    while(j>=0&& (b+j)->p>(key.p)){
        *(b+j+1)=*(b+j);
        j--;
    }
    *(b+j+1)=key;
    rec_ins_sort(b,i+1,n);

}

void display(book*b,int n){
    for(book* i=b;i<(b+n);i++){
        printf("%s %s %d",(i)->title,(i)->author,(i)->p);
    }
}


int main(){
    int n; 
    scanf("%d",&n);
    book b[n];
    for(int i=0;i<n;i++){
        scanf("%s",b[i].title);
        scanf("%s",b[i].author);
        scanf("%d",&b[i].p);
    }
    display(b,n);
    rec_ins_sort(b,1,n);
    printf("sorted now : \n");
    display(b,n);
}