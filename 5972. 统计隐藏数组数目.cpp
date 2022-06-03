

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long a = 0, b = 0, c = 0;
        for (int d : differences) {
            c += d;

            a = min(a, c);
            b = max(b, c);
        }

        cout<<a<<" "<<b<<endl;
        if (b - a > upper - lower) {
            return 0;
        }
        return (upper - lower) - (b - a) + 1;
    }
};


int main(){
    vector<int> res = {1,-3,4};
    int low(1);
    int high(6);

    Solution s;
    cout<<s.numberOfArrays(res, low,high);
    return 0;
}
