#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;
Node* head=NULL;

Node* newNode(int data){
    Node* x= (Node*)malloc(sizeof(Node));
    x->val=data;
    x->next=NULL;
    return x;
}

Node* insertion_begin(int data){
    Node* x= newNode(data);

    if(!head){
        return x;
    }
    else{
        x->next=head;
        head=x;
        return head;
    }
}
void display(){
    Node* temp=head;
    while(temp){
        printf("%d ->",temp->val);
        temp=temp->next;
    }
    printf("\n");
}
void insert_node_after(Node* head,int se){
    Node* temp=head;
    while(temp->val!=se){
        temp=temp->next;
    }
    Node*x=newNode(404);
    x->next=temp->next;
    temp->next=x;
}

Node* delete_node(int data){
    Node*temp=head;
    if(head->val==data){
        Node* q=head;
        head=head->next;
        free(q);
        return head;
    }
    Node*prev=NULL;
    while(temp->val!=data){
        prev=temp;
        temp=temp->next;
    }
    if(temp->next==NULL){
        prev->next=NULL;
        Node* q=temp;
        temp=NULL;
        free(q);
        return head;
    }
    prev->next=temp->next;
    free(temp);
    return head;
}

void reverse(){
    Node* next=NULL,*prev=NULL;
    Node*current=head;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
int main(){ 
    head=insertion_begin(34);
    head=insertion_begin(69);
    head=insertion_begin(77);
    insert_node_after(head,69);
    display();
    head=delete_node(34);
    reverse();
    display();

}