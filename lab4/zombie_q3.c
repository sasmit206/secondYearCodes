/*
Create a zombie (defunct) child process (a child with exit() call, but no
corresponding wait() in the sleeping parent) and allow the init process to adopt it
(after parent terminates). Run the process as background process and run “ps”
command.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
    pid_t pid;
    pid=fork();
    if(pid<0){printf("Failed to create");}
    if(pid==0){
        printf("PID of Zombie CHILD : %d",getpid());
        exit(0);
    }
    else{
        printf("Parent going to sleep..");
        sleep(20);
        printf("LOL");
    }
}