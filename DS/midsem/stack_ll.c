#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int val;
    struct Node* next;
}Node;
struct Node* top=NULL;
void pop(){
    if(!top){printf("stack underflow/empty");
    return;}
    printf("%d",top->val);
    Node* temp=top;
    top=top->next;
    free(temp);
}
void peek(){
    if(top){
    printf("%d",top->val);
    }
    else{printf("stck empty hai boss");}
}
Node* newNode(int data){
    Node* x=(Node*)malloc(sizeof(Node));
    x->val=data;
    x->next=NULL;
    return x;
}
void push(){    
    int se;
    scanf("%d",&se);
    Node* x=newNode(se);
    x->next=top;
    top=x;
}

int main(){
    push();
    pop();
    pop();
    peek();
}