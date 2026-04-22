/*
doubly linked list participants -
each participant has email, name and reg. no
insert new in the middle 
delete first participant registration no.

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    char email[100];
    char name[100];
    int rno;
    struct Node* next;
    struct Node* prev;
}Node;
Node* head=NULL,*temp=NULL;

Node* newNode(char* e,char *n,int r){
    Node* x=(Node*)malloc(sizeof(Node));
    strcpy(x->email,e);
    strcpy(x->name,n);
    x->rno=r;
    x->next=NULL;
    x->prev=NULL;
    return x;
}

int len(){
    Node* t=head;
    int c=0;
    while(t){c++;
    t=t->next;}
    return c;
}

void append(){
    int l=len();
    int i=l/2;
    Node* t=head;
    int j=0;
    while(t){
        j++;
        if(i==j){
            Node* x= newNode("lolxd@reddif.com","lol",2409);
            x->next=t->next;
            t->next->prev=x;
            t->next=x;
            x->prev=t;
            break;
        }
    }
}

void del_f(){
    if(head==NULL||head->next==NULL){
        head=NULL;
        printf("the DLL is now empty");
        return;
    }
    Node* t=head;
    head=head->next;
    head->prev=NULL;
    free(t);
}

void create_part(char* e,char* n,int r){
    Node* x= newNode(e,n,r);
    if(head==NULL)
    {
        head=x;
        head->prev=NULL;
        temp=x;
    }
    else{
        temp->next=x;
        x->prev=temp;
        temp=temp->next;
    }
}

void display(){
    Node* t=head;
    while(t){
        printf("\n %s %s %d \n ",t->email,t->name,t->rno);
        t=t->next;
    }
}
int main(){
    create_part("ama@gmail.com","ama",45);
    create_part("ama@gmail.com","ama",45);
    create_part("ama@gmail.com","ama",45);
    display();
    printf("upon appending: ");
    append();
    display();
    printf("deleting first ele: \n");
    del_f();
    display();
}