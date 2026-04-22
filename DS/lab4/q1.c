/*
Write a menu-driven C program using structures to implement the following operations on a
singly linked list:
➢ Insert an element before another specified element in the list
(Example: Insert 10 before 25)
➢ Insert an element after another specified element in the list
(Example: Insert 40 after 25)
➢ Delete a specified element from the list
(Example: Delete node containing 15)
➢ Traverse the list and display all elements
➢ Reverse the linked list
(Modify the links such that the list is reversed)
➢ Sort the list in ascending order
(Using Bubble Sort or any appropriate algorithm on linked list)
➢ Delete every alternate node in the list
(Starting from the second node)
➢ Insert an element into a sorted linked list while maintaining the sorted order
(Example: Insert 28 into a list that is already sorted)
Requirements
Use dynamic memory allocation (malloc/free) for node creation and deletion.
*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node* next;
}*head= NULL;
struct Node* newNode(int data){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->val=data;
    n->next=NULL;
    return n;
}
void input_insert(int data){
    struct Node *s=newNode(data);
    if(!head){
        head=s;
    }
    else{
        struct Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=s;
    }
}
void sort_LL(struct Node* head){
    for(struct Node*i=head;i!=NULL;i=i->next){
        for(struct Node* j=i;j;j=j->next){
            if(i->val>j->val){
                int temp=i->val;
                i->val=j->val;
                j->val=temp;
            }
        }
    }
}
void delete_alt(struct Node* head){
    int c=0;
    struct Node* temp=head;
    while(temp&&temp->next){
        temp->next=temp->next->next;
        temp=temp->next;
    }
}
void insert_ele__sort_still(struct NOde* head){
    struct Node* temp= head;
    while(temp->next){
        temp=temp->next;
    }
    printf("enter value to be inserted while maintaing the working order of a sorted array :");
    int ele;
    scanf("%d",&ele);
    struct Node* x= newNode(ele);
    temp->next=x;
    sort_LL(head);
}
void display(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->val);
        temp=temp->next;
    }
    printf("nullptr\n");
}
void reverse(struct Node* head){
    struct NOde* temp=head;
    while(temp){
        
    }
}
void delete_node(int data){
    struct Node*temp=head;
    struct Node* prev=temp;
    while(temp!=NULL){
        if(temp->val==data){
            prev->next=temp->next;
        }
        prev=temp;
        temp=temp->next;
    }
}
void insert_before(int se,int ib){
    struct Node*temp=head;
    while(temp->next&&temp){
        if(temp->next->val==se){
            struct Node* x= newNode(ib);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
}
void insert_after(int se,int ib){
    struct Node*temp=head;
    while(temp->next&&temp){
        if(temp->val==se){
            struct Node* x= newNode(ib);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
}
int main(){
    int n;
    printf("enter no of elements to be inputte into the linked list : \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int e;
        scanf("%d",&e);
        input_insert(e);
    }
    display(head);
    int ib,se;
    printf("no before which the element is to be inserted :");
    scanf("%d",&se);
    printf("no to be inserted :");
    scanf("%d",&ib);

    insert_before(se,ib);
    printf("after inserting before: \n");
    display(head);

    insert_after(se,ib);
    printf("after inserting after: \n");
    display(head);

    delete_node(ib);
    printf("after deleting node: \n");
    display(head);

    sort_LL(head);
    printf("after sorting LL: \n");
    display(head);

    delete_alt(head);
    display(head);

    insert_ele__sort_still(head);
    display(head);
}