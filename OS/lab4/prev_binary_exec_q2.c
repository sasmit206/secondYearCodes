/*
Write a C program to load the binary executable of the previous program in a child
process using exec system call.*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    pid=fork();
    
    if(pid<0){printf("Lol failed");}
    if(pid==0){
        execl("./parent_child_q1","parent_child_q1",NULL);
        printf("Failed loading.. ");
        exit(1);
    }
    else{
        wait(NULL);
        printf("Executing Parent...");
    }
}