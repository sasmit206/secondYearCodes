#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct message {  // Same as sender!
    long type;
    char num[100];
};

int main(){
    int id=msgget(1234,0666);  // ← THIS WAS YOUR BUG!
    struct message m;
    msgrcv(id,&m,sizeof(m.num),1,0);       // ← NOW BLOCKS!
    printf("Got: %s\n",m.num);
    
    int i=0,j=strlen(m.num)-1,flag=1;
    for(;i<j;i++,j--) if(m.num[i]!=m.num[j]) flag=0;
    
    if(flag) printf("%s is palindrome\n",m.num);
    else printf("%s is not palindrome\n",m.num);
    return 0;
}
