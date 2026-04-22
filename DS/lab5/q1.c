/*
Write a menu-driven C program using structures to implement the following operations
on a Doubly Linked List.
➢ Insert an element at the rear end of the list
(Append a new node to the end of the list)
➢ Delete an element from the rear end of the list
(Remove the last node in the list)
➢ Insert an element at a given position in the list
(e.g., Insert at position 3. Positioning starts from 1.)
➢ Delete an element from a given position in the list
➢ Insert an element after a node containing a specific value
(e.g., Insert 40 after 25)
➢ Insert an element before a node containing a specific value
(e.g., Insert 10 before 25)
➢ Traverse the list in forward direction
(From head to tail)
➢ Traverse the list in reverse direction
(From tail to head – i.e., reverse traversal)
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node* next;
    struct Node* prev;
}Node;

Node* newNode(int data){
    Node* x = (Node*)malloc(sizeof(Node));
    x->val=data;
    x->next=NULL;
    x->prev=NULL;
    return x;
}
Node* insert_rear(Node* head,int data){
    Node* x= newNode(data);
    if(head==NULL){
        return x;
    }
    else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=x;
        x->prev=temp;
        return head;
    }
}
Node* del_rear(Node* head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    else{
        Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        Node* f=temp->next;
        temp->next=NULL;
        free(f);
        return head;
    }
}
int len(Node* head){
    Node* temp=head;
    int c=0;
    while(temp!=NULL){
        c++;
        temp=temp->next;
        
    }
    return c;
}
Node* insert_pos(Node* head, int pos, int data){
    int l=len(head);
    if(pos>l){
        printf("excceded range of the DLL");
        return head;
    }
    if(pos==0){
        Node* x= newNode(data);
        x->next=head;
        if(head){head->prev=x;}
        head=x;
        return head;
    }
    Node* temp=head;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    Node*copy=temp->next;
    Node* x= newNode(data);
    x->prev=temp;
    temp->next=x;
    x->next=copy;
    if(copy!=NULL)
            copy->prev=x;
    return head;
}
Node* insert_val(Node* head,int data, int value){
    if(head==NULL){return NULL;}
    
    Node* temp=head;
    while(temp!=NULL){
        if(temp->val==data){
            Node* x= newNode(value);
            Node* lol= temp->next;
            temp->next=x;
            x->prev=temp;
            x->next=lol;
            if(lol!=NULL)
                lol->prev=x;
            return head;
        }
        temp=temp->next;
    }
    return head;
}
Node* insert_val_before(Node* head,int data, int element){
    if(head==NULL){return NULL;}
    if(element==head->val){
        Node* x=newNode(data);
        x->next=head;
        head->prev=x;
        head=x;
        return head;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->next->val==element){
            Node* x= newNode(data);
            Node* lol= temp->next;
            temp->next=x;
            x->prev=temp;
            x->next=lol;
            if(lol!=NULL)
                lol->prev=x;
            return head;
        }
        temp=temp->next;
    }
    return head;
}
Node* delete_pos(Node* head, int pos){
    int l=len(head);
    if(pos>=l){
        printf("excceded range of the DLL");
        return head;
    }
    if(pos==0){
        Node* del = head;
        head = head->next;
        if(head) head->prev = NULL;  
        free(del);         
        return head;
    }

    Node* temp = head;
    for(int i=0; i<pos-1; i++){
        temp = temp->next;
    }
    
    Node* del = temp->next;
    temp->next = del->next;
    if(del->next) del->next->prev = temp; 
    free(del);
    return head;
}
void display(Node* head){
    Node* temp=head;
    while(temp){
        printf("%d -> " ,temp->val);
        temp=temp->next;
    }
    printf("nullptr");
}
void traverse_f(Node* head){
    Node* temp=head;
    while (temp!=NULL)
    {
        printf("%d -> ",temp->val);
        temp=temp->next;
    }
    printf("nullptr\n");
}
void traverse_b(Node* head){
    if(head==NULL){return;}
    Node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL){
        printf("%d -> ",temp->val);
        temp=temp->prev;
    }
    printf("nullptr\n");
}
int main(){
    int ch,data;
    Node* head=NULL;
    int flag=1;
    printf("enter choice. : \n 1 to insert element at rear \n 2 to delete element from rear \n 3 to insert a no at a posn \n 4 to delete element from position \n 5 to insert element after inputted value\n 6 to insert element before inputter value \n 7 to traverse LL in forward direction \n 8 to traverse the LL in reverse direction \n");
    scanf("%d",&ch);
    do{
        if(ch==1)
        {
            printf("enter value to be inserted");
            scanf("%d",&data);
            head=insert_rear(head,data);
        }
        else if(ch==2){
            head=del_rear(head);
            display(head);
            break;
        }
        else if(ch==3){
            printf("enter position and no to be appended");
            int pos;
            scanf("%d",&pos);
            scanf("%d",&data);
            head=insert_pos(head,pos,data);
        }
        else if(ch==4){
            printf("enter the posn at which no is to be deleted ");
            int pos;
            scanf("%d",&pos);
            head=delete_pos(head,pos);
        }
        else if(ch==5){
            int value,data;
            printf("enter value to be inputted and the element after which it's to be appended");
            scanf("%d",&value);
            scanf("%d",&data);
            head=insert_val(head,data,value);
        }
        else if(ch==6){
            int value,data;
            printf("enter value to be inputted and the element before which it's to be appended");
            scanf("%d",&value);
            scanf("%d",&data);
            head=insert_val_before(head,data,value);
        }
        else if(ch==7){
            traverse_f(head);
        }
        else if(ch==8){
            traverse_b(head);
        }
        printf("enter choice. : \n 1 to insert element at rear \n 2 to delete element from rear \n 3 to insert a no at a posn \n 4 to delete element from position \n 5 to insert element after inputted value\n 6 to insert element before inputted value \n 7 to traverse LL in forward direction \n 8 to traverse the LL in reverse direction \n");
        scanf("%d",&ch);
    }while(ch==1||ch==2||ch==3||ch==4||ch==5||ch==6||ch==7||ch==8);
    display(head);

}