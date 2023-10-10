

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        vector<int> pre(gain.size()+1,0);
        pre[0] = 0;

        for (int i = 0; i < gain.size(); i++) {
            pre[i+1] = pre[i] + gain[i];
        }

        int maxNum = 0;
        for(auto i:pre) {
            maxNum = max(maxNum,i);
        }
        return maxNum;
    }
};

int main( ) {

    vector<int> nums {-5,1,5,0,-7};
    vector<int> nums2 {-4,-3,-2,-1,4,3,2};

    Solution s2;
    cout<<s2.largestAltitude(nums)<<endl;
    return 0;
}
