/*Create a queue of structures (e.g., queue of patients with name, age, and priority).*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct Node{
    char name[MAX];
    int age;
    int p;
    struct Node* next;
}Node;
Node* front=NULL;
Node* rear=NULL;
int isEmpty(){
    if(front==NULL){
        return 1;
    }
    return 0;
}
Node* newNode(char name[],int age, int p){
    Node* x= (Node*)malloc(sizeof(Node));
    strcpy(x->name,name);
    x->age=age;
    x->p=p;
    x->next=NULL;
    return x;
}
void enqueue(char name[],int age, int p){
    Node* x= newNode(name,age,p);
    if(isEmpty()){
        front=rear=x;
        return;
    }
    Node* temp=front;
    Node* prev=NULL;
    if(front->p>x->p){
        x->next=front;
        front=x;
        return;
    }
    while(temp!=NULL){
        if(temp->p>x->p){
            prev->next=x;
            x->next=temp;
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    prev->next=x;
    x->next=temp;

    return;
}
void dequeue(){
    if(isEmpty()){
        printf("Queue is Empty, Nothing to Dequeue \n");
        return;
    }
    printf("%s Dequeued \n",front->name);
    Node*temp=front;
    front=front->next;
    free(temp);
    return;
}

void display(){
    Node* temp=front;
    if(isEmpty()){
        printf("Queue is empty");
        return;
    }
    while(temp){
        printf("%s - ",temp->name);
        printf("%d - ",temp->age);
        printf("%d - ",temp->p);
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
                printf("enter values (name,age,priority) to be enqueued ");
                int age,p;
                char name[MAX];
                scanf("%s",name);
                scanf("%d",&age);
                scanf("%d",&p);
                enqueue(name,age,p);
                break;
            case 2:
                printf("Dequeing Value..\n");
                dequeue();
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