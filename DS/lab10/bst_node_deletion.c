//Write a function to delete a node from a BST.
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
}Node;
Node* root=NULL;
Node* newNode(int val){
    Node* x=(Node*)malloc(sizeof(Node));
    x->val=val;
    x->left=NULL;
    x->right=NULL;
    return x;
}
Node* insert(int val,Node* root){
    if(root==NULL){return newNode(val);}
    if(val>root->val){
        root->right=insert(val,root->right);
    }
    if(val<root->val){
        root->left=insert(val,root->left);
    }
    return root;
}
Node* min(Node* a){
    while(a&&a->left!=NULL){a=a->left;}
    return a;
}
Node* delete(int del,Node* root){
    if(root==NULL){return root;}
    if(del>root->val){
        root->right=delete(del,root->right);
    }
    else if(del<root->val){
        root->left=delete(del,root->left);
    }
    else{
        if(root->right==NULL&&root->left==NULL){
            free(root);
            return NULL;
        }
        if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else{
            Node*temp=min(root->right);
            root->val=temp->val;
            root->right=delete(temp->val,root->right);
        }
    }
    return root;
}
void inorder(Node* x){
    if(x!=NULL){
        inorder(x->left);
        printf("%d",x->val);
        inorder(x->right);
    }
}
int main(){
    printf("Enter No. of Nodes : \n");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter value: ");
        int val;
        scanf("%d",&val);
        root=insert(val,root);
    }
    printf("Enter value of Node to be deleted : \n");
    int del;
    scanf("%d",&del);
    delete(del,root);
    inorder(root);
}