#include<stdio.h>
#include<stdlib.h>
//Write a program to create an AVL Tree and perform insertion.
typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
    int height;
}Node;
Node* newNode(int val){
    Node* x=(Node*)malloc(sizeof(Node));
    x->left=NULL;
    x->right=NULL;
    x->val=val;
    x->height=1;
    return x;
}
Node* root=NULL;

int getHeight(Node*x){
    if(x==NULL){return 0;}
    return x->height;
}

int getBalanceFactor(Node* x){
    if(x==NULL){return 0;}
    return getHeight(root->left)-getHeight(root->right);
}
int main(){

}