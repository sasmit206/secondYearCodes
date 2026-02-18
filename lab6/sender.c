#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct message {
    long type;
    char num[100];
};

int main() {
    int id = msgget(1234, 0666 | IPC_CREAT);
    
    char n[100];
    printf("Enter no: ");
    scanf("%s", n);
    
    struct message m;           
    m.type = 1;               
    strcpy(m.num, n);          
    msgsnd(id, &m, 100, 0);
    printf("Sent: %s\n", n);
    return 0;
}
