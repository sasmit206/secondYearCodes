/*
Write a C program to define a student structure with the data members to store name,
roll no and grade of the student. Also write the required functions to read, display, and
sort student information according to the roll number of the student. All the member
functions will have array of objects as arguments
*/
#include<stdio.h>
struct student{
    char name[50];
    int roll;
    char grade;
};
void read(struct student s[],int n){
    for(int i=0;i<n;i++){
        printf("enter details of name, roll, grade\n");
        scanf(" %[^\n]", s[i].name);
        scanf("%d",&s[i].roll);
        scanf(" %c",&s[i].grade);
    }
}
void display(struct student s[],int n){
    for(int i=0;i<n;i++){
        printf("%s  %d  %c\n",s[i].name,s[i].roll,s[i].grade);
    }
}
void sort_roll(struct student s[],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n-1;j++){
            if(s[j].roll<s[j+1].roll)
            {
                struct student temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}
int main(){
    int n;
    printf("enter no of students -> ");
    scanf("%d",&n);
    struct student s[n];
    read(s,n);
    display(s,n);
    sort_roll(s,n);
    printf("sorted roll wise: \n");
    display(s,n);

}