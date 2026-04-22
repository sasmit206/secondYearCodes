/*
Write a C program to implement a Circular Singly Linked List using First and Last
pointers.
Implement the following operations:
i. Insertion at the end of the list using First and Last pointers.
ii. Deletion from the beginning or end using First and Last pointers.
iii. Display the list after each operation.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node* next;
}Node;
Node* newNode(int value){
    Node* x=(Node*)malloc(sizeof(Node));
    x->val=value;
    x->next=NULL;
    return x;
}
Node* ins_last_f(Node* head,int value){
    if(head==NULL){
        Node* x=newNode(value);
        x->next=x;
        head=x;
        return head;
    }
    Node* x=newNode(value);
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    x->next=temp->next;
    temp->next=x;
    return head;
}
void display(Node* head){
    if(head==NULL){
        printf("nullptr");
        return;
    }
    Node* temp=head;
    do{
        printf("%d -> ",temp->val);
        temp=temp->next;
    }while(temp!=head);
    printf("back to head");
}
Node* ins_last_l(Node* tail,int value){
    if(tail==NULL){
        Node* x=newNode(value);
        tail=x;
        tail->next=tail;
        return tail;
    }
    Node* x=newNode(value);
    x->next=tail->next;
    tail->next=x;
    return tail;
}
Node* del_f(Node* head){
    if(head==NULL || head->next == head){
    head=NULL;
    return head;
    }
    Node* tail=head;
    while(tail->next!=head){tail=tail->next;}
    tail->next=head->next;
    Node* copy=head->next;
    free(head);
    head=copy;
    return head;
}
Node* del_l(Node* head){
    if(head==NULL || head->next == head){
    head=NULL;
    return head;
    }
    Node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    Node* copy=temp->next;
    temp->next=head;
    free(copy);
    return head;
}
int main(){
    Node* head=NULL,*tail=NULL;
    int ch;
    printf("enter 1 to insert element");
    scanf("%d",&ch);
    do{
    if(ch==1){
        int value;
        printf("enter value to be inserted");
        scanf("%d",&value);
        //head = ins_last_f(head,value);
        if (head == NULL) {
                head = newNode(value);
                head->next = head;
                tail = head;
        }
        else{
            tail=ins_last_l(tail,value);
        }
    }
    if(ch==2){
        head=del_f(head);
    }
    if(ch==3){  
        head=del_l(head);
    }
    printf("enter 1 to insert element");
    scanf("%d",&ch);
    } while(ch==1||ch==2||ch==3);
    display(head);
}