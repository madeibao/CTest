
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> Result(n);
        for (int i = 1; i < n+1; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                Result[i-1] = "FizzBuzz";
            }
            else if (i % 3 == 0) {
                Result[i-1] = "Fizz";
            }
            else if (i % 5 == 0) {
                Result[i-1] = "Buzz";
            }
            else {
                Result[i-1] = to_string(i);
            }
        }
        return Result;
    }
    int n;
};


int main() {

    int n = 3;
    Solution s2;
    vector<string> res;
    res = s2.fizzBuzz(n);
    for(auto i:res) {
        cout<<i<<" ";
    }
    return 0;
}