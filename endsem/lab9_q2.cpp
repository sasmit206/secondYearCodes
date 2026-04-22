/*
Assuming a page size of 32 bytes and there are total of 8 such pages totaling 256 bytes. Write
a C program to simulate this memory mapping. The program should read the logical memory
address and display the page number and page offset in decimal. How many bytes do you
need to represent the address in this scenario? Display the page number and offset to
reference the following logical addresses.
(i) 204 byte (ii) 56 byte
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int i_add;
    int pg=32;
    cout<<"Enter address : ";
    cin>>i_add;
    cout<<"Page No. : "<<i_add/pg;
    cout<<"Offset : "<<i_add%pg;
}