


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n<1) {
            return false;
        }
        if(n==1) {
            return true;
        }
        while(n>0) {
            if(n==1) {
                return true;
            }
            else if(n%5==0) {
                n /=5;
            }
            else if(n%3==0) {
                n /=3;
            }
            else if(n%2==0) {
                n /=2;
            }
            else {
                return false;
            }
        }

        return n==1;
    }
};


int main() {



    return 0;
}