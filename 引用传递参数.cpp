

/**
    b作为a的引用，
    b改变，
    a也要改变
    

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a= 3;
    int &b = a;
    b+=1;
    cout<<a;


    return 0;
}
