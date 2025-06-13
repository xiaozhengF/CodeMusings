#include<cstdio>
#include<iostream>
using namespace std;
struct node{
    char cha;
    int num;
}st;
int main(void){
    int a[100];
    char b[100];
    cout << sizeof(int) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(st) << endl;
    return 0;
}