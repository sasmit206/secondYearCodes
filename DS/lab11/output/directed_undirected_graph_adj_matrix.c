#include<stdio.h>

int main(){
    printf("Enter No of Vertices : ");
    int adj[10][10]={0};
    int v;
    scanf("%d",&v);
    printf("Enter 1 for Directed graph, 2 to Undirected Graph : \n");
    int ch;
    scanf("%d",&ch);
    printf("enter no of edges:\n");
    int e;
    scanf("%d",&e);
    for(int i=0;i<e;i++){
        int x,y;
        printf("Enter edges (x,y) : \n");
        scanf("%d %d",&x,&y);
        adj[x][y]=1;
        if(ch==2){adj[y][x]=1;}
    }
    printf("The Adjacency Matrix is : \n");
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            printf("%d",adj[i][j]);
        }
        printf("\n");
    }

}