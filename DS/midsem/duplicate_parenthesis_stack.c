#include<stdio.h>
#define MAX 100
int hasDuplicateParenthesis(char expr[]){
    char stack[MAX];
    int top=-1;

    for(int i=0;expr[i]!='\0';i++){
        if(expr[i]==')'){
            if(top!=-1&&stack[top]=='('){
                return 1;
            }
            int ele_c=0;
            while(top!=-1&&stack[top]!='('){
                ele_c++;
                top--;
            }
            if(top!=-1){
                top--;
            }
            if(ele_c==0){
                return 1;
            }

        }
        else{
            stack[++top]=expr[i];
        }
    }
    return 0;
}
int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    fgets(expr,100,stdin);

    if (hasDuplicateParenthesis(expr)==1)
        printf("Duplicate parentheses found.\n");
    else
        printf("No duplicate parentheses.\n");

    return 0;
}