//Write a function to find the minimum and maximum elements in a BST

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
}Node;
Node* root=NULL;
int searchmin(Node* root){
    while(root&&root->left!=NULL){root=root->left;}
    return root->val;
}
int searchmax(Node* root){
    while(root&&root->right!=NULL){root=root->right;}
    return root->val;
}
Node* newNode(int val){
    Node* x=(Node*)malloc(sizeof(Node));
    x->val=val;
    x->left=NULL;
    x->right=NULL;
    return x;
}
Node* insert(Node* root,int val){
    if(root==NULL){return newNode(val);}
    if(val>root->val){root->right=insert(root->right,val);}
    if(val<root->val){root->left=insert(root->left,val);}
    return root;
}
int main(){
    printf("Enter No. of Nodes : \n");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter value: ");
        int val;
        scanf("%d",&val);
        root=insert(root,val);
    }
    printf("Maximum Value in BST: %d\n",searchmax(root));
    printf("Minimum Value in BST: %d\n",searchmin(root));
}