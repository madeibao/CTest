

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string add(int a, int b) {
        if(a==b) {
            return to_string(a);
        }
        else {
            return to_string(a)+"->"+to_string(b);
        }
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
    
        int n = nums.size();
        if(n==0) {
            return {};
        }

        vector<string> res;

        int start = nums[0];
        int end = nums[0];

        for(int i=1;i<nums.size();i++) {
            if(end == nums[i]) {
                end = nums[i];
            }
            else {
                res.push_back(add(pre,end))
                start = nums[i];
                end = nums[i];
            }
        }

        res.push(add(pre,end));
        return res;
    }
};


int main() {

    vector<int>nums = {0,1,2,4,5,7};
    Solution s2;
    vector<string> res;
    res = s2.summaryRanges(nums)<<endl;
    return 0;
}