/*Write a program to create a BST and perform inorder, preorder, and postorder
traversals.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
}Node;
Node* newNode(int val){
    Node* x=(Node*)malloc(sizeof(Node));
    x->val=val;
    x->right=NULL;
    x->left=NULL;
    return x;
}
Node* root=NULL;
void inorder(Node* x){
    if(x!=NULL){
        inorder(x->left);
        printf("%d",x->val);
        inorder(x->right);
    }
}
void preorder(Node* x){
    if(x!=NULL){
        printf("%d ",x->val);
        preorder(x->left);
        preorder(x->right);
    }
}
void postorder(Node* x){
    if(x!=NULL){
        postorder(x->left);
        postorder(x->right);
        printf("%d ,",x->val);
    }
}

Node* newchild(int val,Node* root){
    if(root==NULL){
        return newNode(val);
    }
    if(val>root->val){
        root->right=newchild(val,root->right);
    }
    if(val<root->val){
        root->left=newchild(val,root->left);
    }
    return root;
}
int main(){
    int n;
    Node* temp=NULL;
    int val;
    printf("Enter no of nodes");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter value of %d node",i+1);
        scanf("%d",&val);
        root=newchild(val,root);
    }
    printf("Enter 1 for PreOrder, 2 for PostOrder, 3 for Inorder");
    int ch;
    scanf("%d",&ch);
    switch(ch){
        case 1:
            preorder(root);
            break;
        case 2:
            postorder(root);
            break;
        case 3:
            inorder(root);
            break;
    }
}