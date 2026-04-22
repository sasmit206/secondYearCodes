/*
Q1) Write a menu driven program to implement a Child Health Status database management system storing the following values
Child ID (int)
Name (String)
Age (int)
Gender (String)
Health Status (String)
Provide the user with the following options:
1) Selection Sort (Recursive implementation only)
2) Display all records

Q2) Implement a Booking system using doubly linked list storing the following information:
Booking ID (int)
Customer Name (String)
Service or Event (String)
Seats Booked (int)
Price per Seat (float)
Following options must be provided to the user
1) Add a node (Priority (i.e., VIP customer must be added in the beginnign), and regular customers at the end as usual)
2) Display the total bill of a customer (Based on any field)
3) Display the Booking List
*/
#include<stdio.h>
typedef struct child{
    int id;
    char name[100];
    int age;
    char gender[100];
    char hs[100];
}child;
void display(child *c,int n){
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%s\t%s\t%s\n",c[i].id,c[i].age,c[i].name,c[i].gender,c[i].hs);
    }
}
void rec_sel_sort(child *c,int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i;j<n;j++){
            if(c[min].age>c[j].age){
                min=j;
            }
        }
        if(c[min].age!=c[i].age){
            child temp=c[min];
            c[min]=c[i];
            c[i]=temp;
        }
    }
}
int main(){
    int n;
    printf("enter no of children");
    scanf("%d",&n);
    child c[n]; 
    for(int i=0;i<n;i++){
        scanf("%d\t%d %[^\n] %[^\n] %[^\n]",&c[i].id,&c[i].age,c[i].name,c[i].gender,c[i].hs);
    }
    printf("id \t age\t name \t gender \t health status \n");
    display(c,n);
    printf("after sorting:\n");
    rec_sel_sort(c,n);
    display(c,n);

}