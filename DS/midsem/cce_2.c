/*
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
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    int bid;
    char name[100];
    char e[100];
    int seats;
    float pps;
    struct Node* next;
    struct Node* prev;
}Node;
Node* head=NULL,*temp=NULL;
void add_node(){
    Node* x=(Node*)malloc(sizeof(Node));
    int bid,s;
    float pps;
    char name[100],e[100];
    printf("Enter Booking ID:\n");
    scanf("%d", &x->bid);
    getchar(); // consume leftover newline

    printf("Enter Seats Booked:\n");
    scanf("%d", &x->seats);
    getchar();

    printf("Enter Price per Seat:\n");
    scanf("%f", &x->pps);
    getchar();

    printf("Enter Customer Name:\n");
    scanf("%[^\n]", name);
    getchar();

    printf("Enter Service/Event:\n");
    scanf("%[^\n]", e);
    getchar();
    getchar();
    x->bid=bid;
    x->seats=s;
    x->pps=pps;
    strcpy(x->name,name);
    strcpy(x->e,e);
    x->next=NULL;
    x->prev=NULL;
    if(head==NULL){
        head=x;
        temp=x;
    }
    else{
        temp->next=x;
        x->prev=temp;
        temp=temp->next;
    }
}
void display_bill(){
    Node* t= head;
    while(t){
        printf("%d %d %f %s",t->bid,((t->seats)*(t->pps)),t->name);
        t=t->next;
    }
}
void display_list(){

}
int main(){
    int ch=0;
    do{
        add_node();
        printf("enter 1 to continue inputting elements");
        scanf("%d",&ch);
    }while(ch==1);
    display_bill();

}