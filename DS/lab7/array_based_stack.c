/*
Array-Based Stack
i. Check whether a given string is a palindrome using stack.
➤ Use character stack to compare original and reversed string.
ii. Check for matching parentheses in each expression.
➤ Push opening brackets, pop for matching closing brackets
*/
#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct Stack{
    char arr[MAX];
    int top;
}Stack;

void init(Stack*s){
    s->top=-1;
}
void push(char c,Stack *s){
    if(s->top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)]=c;
}
char pop(Stack*s){
    if(s->top<0){printf("Stack UNderflow");
    return '\0';}
    return s->arr[(s->top)--];
}
void isPalin(){
    char ch[100],rev[100];
    Stack s;
    init(&s);
    printf("ENTER STRING :");
    scanf("%s",ch);
    for(int i=0;i<strlen(ch);i++){
        push(ch[i],&s);
    }
    for(int i=0;i<strlen(ch);i++){
        rev[i]=pop(&s);
    }
    rev[strlen(ch)]='\0';
    printf("%s _ %s",rev,ch);
    if(strcmp(rev,ch)==0){
        printf("String is Palindrome");
    }
    else{
        printf("String NOT Palindrome");
    }
}
int isEmpty(Stack *s){
    if(s->top==-1){return 1;}
    return 0;

}
int isMatching(char open,char close){
    if(open=='('&&close==')'||open=='{'&&close=='}'||open=='['&&close==']'){
        return 1;
    }

    return 0;
}
void isParen(){
    char exp[MAX];
    printf("Enter Expression");
    scanf("%s",exp);
    Stack s2;
    init(&s2);
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
            push(exp[i],&s2);
        }
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(isEmpty(&s2)){
                printf("Invalid Expression ! ");
                return;
            }
            if(!isMatching(pop(&s2),exp[i])){printf("Invalid Expression ! ");}
        }
    }
    if(isEmpty(&s2)){printf("VAlID Exp 🎉");}
    else{printf("Hat be Invalid hai Bola Toh");}
}
int main(){
    isPalin();
    isParen();
}