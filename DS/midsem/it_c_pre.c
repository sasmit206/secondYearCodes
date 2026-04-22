/*
Q. Write a menu-driven program in C using structures and pointers for handling a collection of books.
Each book has the following information:

Title

Author

Price

The program should provide the following menu options:

Create / Add books (input details of n books).

Display all books.

Sort books by price using recursive Selection Sort (use pointer arithmetic for accessing structure members).

Exit.

Implement recursive selection sort to sort the array of structures based on the price field.
Demonstrate the program with proper input and output.
*/

#include<stdio.h>
typedef struct Book{
    char t[100];
    char a[100];
    int p;
}Book;

void rec_sel_sort(Book* b,int n){
    if(n<=1){return;}
    Book *min=b;
    for(int j=1;j<n;j++){
        if((b+j)->p>min->p){
            min=b+j;
        }
    }
    Book temp=*min;
    *min=*(b);
    *(b)=temp;
    rec_sel_sort(b+1,n-1);
}
void display(Book* b,int n){
    for(int i=0;i<n;i++){
        printf("%s \t",(b+i)->t);
        printf("%s \t",(b+i)->a);
        printf("%d \t",(b+i)->p);
        printf("\n");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    Book b[n];
    for(int i=0;i<n;i++){
        scanf("%s",b[i].t);
        scanf("%s",b[i].a);
        scanf("%d",&b[i].p);
    }
    display(b,n);
    
    rec_sel_sort(b,n);
    display(b,n);
}