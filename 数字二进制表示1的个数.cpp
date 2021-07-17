

#include<iostream>
#include<bits/stdc++.h>

using namespace std; //

class Solution {
public:
    int getSum(int x) { 
        int res =0;

        while(x!=0) {
            x = x&(x-1);
            res++;
        }
        return res;
    }
};

int main(int argc, char* argv[]) {

    int n =15;
    Solution s;
    cout<<s.getSum(n)<<endl;
    return 0;
}