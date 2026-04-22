/*Implement a queue using a singly linked list with enqueue and dequeue operations.*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int val;
    struct Node* next;
}Node;
Node* front=NULL;
Node* rear=NULL;
Node* newNode(int val){
    Node* x= (Node*)malloc(sizeof(Node));
    x->val=val;
    x->next=NULL;
    return x;
}
int isEmpty(){
    if(front!=NULL){return 0;}
    return 1;
}
void enqueue(int val){
    Node* x=newNode(val);
    if(x==NULL){
        printf("Memory Allocation Failed ! ");
        return;
    }
    if(isEmpty()){
        front=rear=x;
        return;
    }
    rear->next=x;
    rear=rear->next;
}

int dequeue(){
    if(isEmpty()){
        printf("The Queue is Empty ! ");
        return -1;
    }
    int temp=front->val;
    Node* copy=front;
    front=front->next;
    free(copy);
    return temp;
}

void display(){
    Node* temp=front;
    if(isEmpty()){
        printf("Queue is empty");
        return;
    }
    while(temp){
        printf("%d -",temp->val);
        temp=temp->next;
    }
}

int main(){
    int op;
    do{
        printf("Enter 1 to enqueue, 2 to dequeue, 3 to display");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("enter value to be enqueued ");
                int val;
                scanf("%d",&val);
                enqueue(val);
                break;
            case 2:
            printf("Dequeing Value..\n");
                int d=dequeue();
                printf("%d\n",d);
                break;
            case 3:
            printf("Queue Displayed : \n");
                display();
                break;
            default:
                printf("Exiting...👺\n");
        }
    }while(op==1||op==2||op==3);
    display();
}