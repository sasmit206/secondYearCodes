/*
Write a program to perform following string operations without using string
handling functions:
a.) length of the string
b.) string concatenation
c.) string comparison
d.) to insert a sub string
e.) to delete a substring
*/
#include<stdio.h>
#include<stdlib.h>
int len_st(char* ch){
    int c=0;
    while(*ch != '\0'){
        ch++;
        c++;
    }
    return c;
}
char* concatenate_str(char* str1, char* str2){
    int l1=len_st(str1);
    int l2=len_st(str2);
    char* str3=(char*)malloc((l1+l2+1)*sizeof(char));
    for(int i=0;i<l1;i++)
        str3[i]=str1[i];
    for(int i=0;i<l2;i++){
        str3[l1+i]=str2[i];
    }
    str3[l1+l2]='\0';
    return str3;
}
int str_cmp(char*str1,char*str2){
    while(str1&&str2){
        if(*str1!=*str2)
        {
            if(*str1-*str2<0)
                return -1;
            else 
                return 1;
        }
        str1++;
        str2++;
    }
    if(*str1!='\0'){
        return 1;
    }
    else{
        return -1;
    }
    return (0);
}
char* ins_sub_str(char*str1){
    int idx;
    char subs[100];
    printf("enter substring to be added & the index at which its to be appended");
    scanf("%s",subs);
    scanf("%d",&idx);
    
    int ls=len_st(str1);
    if(idx>ls){
        printf("you have exceeded length of orignal array");
        return str1;
    }
    int len_sub=len_st(subs);
    char* strf=(char*)malloc((ls+len_sub+1)*sizeof(char));
    for(int i=0;i<idx;i++){
        strf[i]=str1[i];
    }
    
    for(int i=0;i<len_sub;i++){
        strf[idx+i]=subs[i];
    }
    for(int i=0;i<(ls-idx-len_sub);i++){
        strf[len_sub+ls+i]=str1[i];
    }
    return strf;
}

int main(){
    char ch[100],ch_c[100];
    scanf("%s",ch);
    int length=len_st(ch);
    scanf("%s",ch_c);
    printf("%d is length of the string %s ",length,ch);
    char* str3=concatenate_str(ch,ch_c);
    printf("\n%s is the concatenated string",str3);
    int comp=str_cmp(ch,ch_c);
    printf("the comparison resulted in %d",comp);
    char* str_con=ins_sub_str(ch);
    printf("%s is the concatenated string",str_con);
}