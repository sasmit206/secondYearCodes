#include<string.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdio.h>

struct message{
    long type;
    char x;
};

int main(){
    int id=msgget(1234,0666);
    struct message m;
    msgrcv(id,&m,sizeof(m.x),1,0);
    if(m.x==90){printf("A\n");}
    else if(m.x==122){printf("a\n");}
    else{printf("%c\n",(m.x)+1);}
}

