

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n==1) {
            return 1;
        }

        if(n==2) {
            return 1;
        }

        int a =1;
        int b =1;

        int c =0;
        for(int i=3;i<=n;i++) {
            c = a+b;
            a=b;
            b=c;
        }

        return c;
    }
};


int main() {


	return 0;
}