

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int len = digits.size();
        for(int i=len-1;i>=0;i--) {
            digits[i] = (digits[i]+1)%10;
            if(digits[i]!=0){
                return digits;
            }
        }

        vector<int> temp(len+1,0);
        temp[0] = 1;
        return temp;
    }
};

int main( ) {

    vector<int> nums = {1,2,3};
    vector<int> res;
    Solution s2;
    res = s2.plusOne(nums);
    for(int i:res) {
        cout<<i<<" ";
    }
    return 0;
}
