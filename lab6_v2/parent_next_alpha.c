/*
Implement a parent process, which sends an English alphabet to child process using shared
memory. Child process responds back with next English alphabet to the parent. Parent
displays the reply from the Child.
*/
#include<stdio.h>
#include<sys/types.h> 
#include<sys/shm.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
    int shmid=shmget(1234,1024,0666|IPC_CREAT);
    char *ch=shmat(shmid,NULL,0);
    printf("Enter alphabet");
    scanf("%c",ch);
    int pid=fork();
    if(pid==0){
        *ch=*ch+1;
    }
    else{
        wait(NULL);
        printf("%c",*ch);
    }

}