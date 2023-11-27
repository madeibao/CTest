

#include <iostream>
#include <stdlib.h>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSelfDividing(int num) {
        int temp=num;
        while(temp) {
            int tmp=temp%10;
            if(tmp==0 || num%tmp!=0) return false;
            temp/=10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left;i<=right;i++)
            if(isSelfDividing(i))
                res.emplace_back(i);
                // res.push_back(i);
        return res;
    }
};

int main() {

    int  left = 1, right = 22;
    Solution s2;
    vector<int> res;
    res = s2.selfDividingNumbers(left,right);

    for(auto i:res) {
        cout<<i<<" ";
    }
    return 0;
}
