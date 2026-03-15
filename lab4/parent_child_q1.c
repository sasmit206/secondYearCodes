/*
Write a C program to create a child process. Display different messages in parent
process and child process. Display PID and PPID of both parent and child process.
Block parent process until child completes using wait system call.*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
    pid_t pid;
    pid=fork();
    if(pid<0){printf("Invalid");}
    if(pid==0){
        printf("Child created PID: %d PPID : %d\n",getpid(),getppid());
    }
    else{
        wait(NULL);
        printf("Parent : pid : %d ppid : %d",getpid(),getppid());
    }
}