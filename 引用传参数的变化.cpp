
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

// 直接的调用
int change2(int a) {

	a =a+1;
	return a;
}

int change3(int *b) {
    *b =*b +1;
    return *b;
}


int change4(int &c) {
    c =c+1;
    return c;
}

int main(int argc, char* argv[]) {

	int a=1;
	cout<<change2(a)<<endl;
	cout<<a<<endl;
    cout<<"----------------------------------------"<<endl;
    int b=1;
    cout<<change3(&b)<<endl;
    cout<<b<<endl;
    cout<<"----------------------------------------"<<endl;
    int c=1;
    cout<<change4(c)<<endl;
    cout<<c<<endl;

	return 0;
}


/**
    2
    1
    ----------------------------------------
    2
    2
    ----------------------------------------
    2
    2

*/

