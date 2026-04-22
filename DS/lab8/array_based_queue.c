/*
Array-Based Queue Implementation:
1. Write a C program to simulate a printer queue where tasks arrive randomly and are
processed in order.
i. Tasks (with a document ID and name) arrive at random (simulate using
random function or user input).
ii. Enqueue each print job.
iii. Dequeue in FIFO order to simulate printing
*/

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define MAX 100
typedef struct Tasks{
    int id;
    char tname[MAX];
}Tasks;
struct Tasks queue[MAX];
int rear=-1;
int front=-1;

int isEmpty(){
    if(rear==front){
    return 1;}
    return 0;
}

int isFull(){
    if(!isEmpty()&&rear==MAX-1){
        return 1;
    }
    return 0;
}

void enqueue(struct Tasks task){
    if(isFull()){
        printf("The Queue is FUll !");
        return;
    }
    queue[++rear]=task;
}
Tasks dequeue(){
    if(isEmpty()){
        rear=front=-1;
        struct Tasks lol = {0," "};
        return lol;
    }
    struct Tasks lol;
    lol=queue[front++];
    return lol;
}

Tasks peek(){
    if(isEmpty()){
        printf("The queue is empty bhau");
        Tasks lol={0," "};
        return (lol);
    }
    return queue[front+1];
}
void display(){
    if(isEmpty()){printf("Empty Queue, Cant Display!");}
    for(int i=front+1;i<=rear;i++){
        printf("%d : %s \n",queue[i].id,queue[i].tname);
    }
}

int main(){
    srand(time(0));
    int n;
    printf("Enter Tot no of tasks");
    scanf("%d",&n);
    char** names=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        names[i]=(char*)malloc(sizeof(char));
        printf("Enter Task:\n");
        scanf("%s",names[i]);
    }
    int ch=1;
    do{
        struct Tasks t;
        t.id=rand()%1000;
        strcpy(t.tname,names[rand()%n]);
        enqueue(t);
        printf("Enter 1 to continue adding tasks, 2 or any other no. to exit");
        scanf("%d",&ch);
    }while(ch==1);
    display();

}