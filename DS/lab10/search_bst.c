#include<stdio.h>
#include<stdlib.h>
//Write a function to search an element in a BST.
typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
}Node;
Node* root=NULL;
void search(int se,Node* root){
    if(root!=NULL){
    if(se==root->val){printf("%d found ",se);return;}
    if(se>root->val){search(se,root->right);}
    if(se<root->val){search(se,root->left);}
    }   
    else{
        printf("Element Not Found :(");
    }
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
    printf("Enter element to be searched : \n");
    int se;
    scanf("%d",&se);
    search(se,root);
}