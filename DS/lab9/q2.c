/*
 Write a recursive function to:
i) Create a binary tree
ii) Print the binary tree (in traversal order, typically level-order)
*/
#include<stdio.h>
#include<stdlib.h>
int currsize=0;
typedef struct TreeNode{
    int val;
    struct TreeNode* right;
    struct TreeNode* left;
}TreeNode;

typedef struct Node{
    TreeNode* nodeData;
    struct Node* next;
}Queue;
Queue* front=NULL;
Queue* rear=NULL;


void enqueue(TreeNode* cnt){
    Queue* x=(Queue*)malloc(sizeof(Queue));
    x->nodeData=cnt;
    x->next=NULL;

    if(front==NULL){
        front=x;
        rear=x;
        currsize++;
    }
    else{
        rear->next=x;
        rear=x;
        currsize++;
    }
}
TreeNode* dequeue(){
    if(!front){return NULL;}
    Queue* f=front;
    TreeNode* return_val=front->nodeData;
    front=front->next;
    free(f);
    currsize--;
    return return_val;
}
void printBinaryTree_Level_Order(TreeNode* head){
    enqueue(head);
    while(currsize!=0){
        TreeNode* cnt=dequeue();
        printf("%d ,",cnt->val);
        if(cnt->left){enqueue(cnt->left);}
        if(cnt->right){enqueue(cnt->right);}
    }
    
}

TreeNode* createBinary(){
    int par;
    printf("Enter data (-1 for NULL/ending creation)");
    scanf("%d",&par);
    if(par==-1){return NULL;}
    TreeNode* head =(TreeNode*)malloc(sizeof(TreeNode));
    head->val=par;

    int ch;
    printf("enter 1 to add a right child");
    scanf("%d",&ch);
    if(ch){
    printf("For right child's value : ");
    head->right=createBinary();
    }
    else{
        head->right=NULL;
    }

    printf("enter 1 to add a left child");
    scanf("%d",&ch);
    if(ch){
    printf("For left child's value:");
    head->left=createBinary();
    }
    else{
        head->left=NULL;
    }
    return head;
}
void main(){
    TreeNode*head=createBinary();
    printBinaryTree_Level_Order(head);
}