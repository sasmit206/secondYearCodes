#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/types.h>

struct message {
    long id;
    long num;
}typedef message;

int main(){
    long id=msgget(1234,0666|IPC_CREAT);
    message m;
    msgrcv(id,&m,sizeof(m.num),1,0);
    int copy=m.num;
    int rev=0;
    while(copy){
        int d= copy%10;
        rev=rev*10+d;
        copy/=10;
    }
    if(rev==m.num){printf("%ld is Palindrome",m.num);}
    else{printf("%ld is not Palindrome",m.num);}
}