/*
Define a structure Student with the following members:
char name [50] – to store student name as a string
int roll_no – to store roll number
float marks – to store marks
Write a C program that:
i. Reads the details of ‘n’ students using a function that uses pointer to structure
as an argument.
ii.  Displays the details of all students using a separate function.
iii. Finds and displays the student with the highest marks using pointer-based
access.
*/
#include<stdio.h>
struct Student {
    char name[50];
    int roll_no;
    float marks;
};
void read(struct Student* s,int n){
    for(int i=0;i<n;i++){
        printf("enter name\n");
        scanf(" %[^\n]",(s+i)->name);
        printf("enter roll no \n");
        scanf("%d",&(s+i)->roll_no);
        printf("enter marks \n");
        scanf("%f",&(s+i)->marks);
    }
}
void display(struct Student* s,int n){
    for(int i=0;i<n;i++){
        printf("%s\t",(s+i)->name);
        printf("%d\t",(s+i)->roll_no);
        printf("%f\t",(s+i)->marks);
        printf("\n");
    }
}
void find_tpr(struct Student* s,int n){
    int flag=0;
    float max=s[0].marks;
    for(int i=1;i<n;i++){
        if((s+i)->marks>max)
            flag=i;
    }
    printf("the topper details are: \n");
    printf(" %s\n",(s+flag)->name);
    printf("%d\n",(s+flag)->roll_no);
    printf("%f\n",(s+flag)->marks);
}
void main(){
    int n;
    printf("enter no of elements-> ");
    scanf("%d",&n);
    struct Student s[n];
    read(s,n);
    display(s,n);
    find_tpr(s,n);
}