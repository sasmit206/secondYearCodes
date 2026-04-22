#include<stdio.h>
void rec_bs_search(int arr[],int f,int l,int se){
    if(f>l){return;}
    int mid=f+(l-f)/2;
    if(arr[mid]==se){printf("found");
    return;}
    if(arr[mid]>se){l=mid-1;}
    if(arr[mid]<se){f=mid+1;}
    rec_bs_search(arr,f,l,se);

}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int se;
    scanf("%d",&se);
    rec_bs_search(arr,0,n-1,se);
}