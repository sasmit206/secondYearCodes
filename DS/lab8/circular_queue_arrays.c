//Write a C program to implement a circular queue using arrays.
#include<stdio.h>
#define MAX 5
int rear=-1;
int front=-1;
int currsize=0;
int queue[MAX];

int isEmpty(){
    if(currsize==0){return 1;}
    return 0;
}
void enqueue(int val){
    if(currsize==MAX){
        printf("Queue is FUll ~ Stack Overflow !");
        return;
    }
    if(isEmpty()){
        rear=front=0;
        currsize=1;
        queue[rear]=val;
        return;
    }
    rear=(rear+1)%MAX;
    queue[rear]=val;
    currsize++;
    return;
}
int dequeue(){
    if(isEmpty()){
        printf("Queue is Empty bhai");
        return -1;
    }
    front=(front+1)%MAX;
    int r = queue[front];
    currsize--;
    return r;
}
void peek(){
    if(isEmpty()){printf("EMPTY QUEUE");
    return;}
    printf("%d",queue[front+1]);
}
void display(){
    int x=front;
    for(int i=0;i<currsize;i++){
        printf("%d",queue[x]);
        x=(x+1)%MAX;
    }
}
int main() {
    int choice, val;
    do {
        printf("CHoices: ");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                val = dequeue();
                if (val != -1)
                    printf("Dequeued: %d\n", val);
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}