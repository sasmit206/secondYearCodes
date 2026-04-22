#include<stdio.h>
#define max 3
int stack[max],top=-1;
void peek(){
    if(top==-1){printf("stack underflow");
    return;}
    int ele = stack[top];
    printf("%d is the top element peeked",ele);
}
void push(){
    int ele;
    printf("Enter no. To be Pushed");
    scanf("%d",&ele);
    if(top==max-1){printf("stack overflow");
    return;}
    stack[++top]=ele;
}
void pop(){
    if(top==-1){printf("stack underflow");
    return;}
    int ele = stack[top--];
    printf("%d popped",ele);
}
int main(){
    push();
    pop();
    push();
    push();
    push();
    push();
    push();
    peek();
    pop();
    

}