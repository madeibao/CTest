

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    char str[9][5]={{'a','b','c'},"def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    for(int i=0;i<9;i++) {
        for(int j=0;j<5;j++) {
            cout<<str[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
