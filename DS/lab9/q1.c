/*
Write user-defined functions to perform the following operations on binary trees:
i) Inorder traversal (Iterative)
ii) Postorder traversal (Iterative)
iii) Preorder traversal (Iterative)
iv) Print the parent of a given element
v) Print the depth (or height) of the tree
vi) Print the ancestors of a given element
vii) Count the number of leaf nodes in a binary tree
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node* rchild;
    struct Node* lchild;
}Node;
Node* head=NULL;
int flag=0;
void inorder(Node* temp){
    if(temp==NULL){return;}
    inorder(temp->lchild);
    printf("%d , ",temp->val);
    inorder(temp->rchild);
}
void postorder(Node* temp){
    if(temp==NULL){return;}
    postorder(temp->lchild);
    postorder(temp->rchild);
    printf("%d , ",temp->val);
}
void preorder(Node* temp){
    if(temp==NULL){return;}
    printf("%d , ",temp->val);
    preorder(temp->lchild);
    preorder(temp->rchild);
}

void printDepth(Node* x,int val,int c){
    if(x==NULL){return;}
    if(x->val==val){
        printf("\n%d is depth of %d",c,val);
        return;}
    printDepth(x->rchild,val,c+1);
    printDepth(x->lchild,val,c+1);
}
int printAncestors(Node* x,int val){
    if(x==NULL){return 0;}
    if(x->val==val){return 1;}
    if(printAncestors(x->rchild,val)||printAncestors(x->lchild,val)){
        printf("%d ,",x->val);
        return 1;
    }
    return 0;
}
Node* newNode(int val){
    Node* x= (Node*)malloc(sizeof(Node));
    x->val=val;
    x->rchild=NULL;
    x->lchild=NULL;
    return x;
}

void printParent(Node* x,int val){
    if(x==NULL){return;}
    if(x->lchild && x->lchild->val==val){printf("%d is the parent of %d",x->val,val);
    flag=1;}
    if(x->rchild && x->rchild->val==val){printf("%d is the parent of %d",x->val,val);
    flag=1;}
    printParent(x->lchild,val);
    printParent(x->rchild,val);
}
void leafcount(Node*x,int *c){
    if(x==NULL){return;}
    if(x->rchild==NULL&&x->lchild==NULL){
        *(c)=*(c)+1;
        return;}
    leafcount(x->lchild,c);
    leafcount(x->rchild,c);
}
int main(){
    head=newNode(5);
    head->lchild=newNode(4);
    head->rchild=newNode(7);
    head->lchild->lchild=newNode(3);
    head->rchild->rchild=newNode(8);
    head->rchild->lchild=newNode(6);
    printf("PostOrder -> ");
    postorder(head);
    printf("\n");
    printf("PreOrder ->  ");
    preorder(head);
    printf("\n");
    printf("InOrder  ->  ");
    inorder(head);
    printf("\n");
    printf("Enter Value of Node whose Parent has to be found");
    int per;
    scanf("%d",&per);
    if(per==head->val){printf("You have entered head Node");
    flag=1;}
    printParent(head,per);
    if(flag==0){printf("No parent found, %d Node is adopted",per);}
    int c=0;
    printf("\n enter whose depth is to be found : ");
    int per2;
    scanf("%d",&per2);
    printDepth(head,per2,0);
    printf("\nEnter Node whose ancestors are to be printed");
    int anc;
    scanf("%d",&anc);
    printf("\n Ancestors: ");
    printAncestors(head,anc);
    int lc=0;
    leafcount(head,&lc);
    printf("\nLeafcount of Tree :");
    printf("%d",lc);
}