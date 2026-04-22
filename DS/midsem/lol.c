/*
A bus route management using singly linked lists
ROUTE A AND ROUTE B
1) for route A function for inserting a bus stop before a specified stop
2) Add and display BUS STOPS for respective Routes
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    char stop[100];
    struct Node* next;
}Node;
Node* newNode(char*c){
    Node* x= (Node*)malloc(sizeof(Node));
    strcpy(x->stop,c);
    x->next=NULL;
    return x;
}
Node* insert_stop(Node* r){
    Node* x= newNode("loll");
    
    if(!r){
        r=x;
    }
    else{
        Node* temp=r;
        while(temp->next){temp=temp->next;}
        temp->next=x;
        temp=temp->next;
    }
    return r;

}

void display(Node* r){
    while(r){
        printf("%s -> ",r->stop);
        r=r->next;
    }
}
void insert_after(Node* r,char* se){
    while(r){
        if(strcmp(r->stop,se)==0){
            Node* temp=r->next;
            Node* x= newNode("lund");
            r->next=x;
            x->next=temp;
            break;
        }
        r=r->next;
    }
}
int main(){
    Node *rA=NULL,*rB=NULL;
    rA=insert_stop(rA);
    rA=insert_stop(rA);
    rB=insert_stop(rB);
    printf("before which stop is to be inserted");
    char se[100];
    scanf("%[^\n]",se);
    display(rA);
    insert_after(rA,se);
    display(rA);
}