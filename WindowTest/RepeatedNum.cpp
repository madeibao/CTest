

// 滑动窗口应用
// 是否存在重复的元素内容


#include "iostream"
#include "bits/stdc++.h"

using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        int n = nums.size();

        for(int i=0;i<n;i++) {
            if(hash.find(nums[i])!=hash.end()) {
                if(i-hash[nums[i]]<=k) {
                    return true;
                }
            }
            hash[nums[i]] = i;
        }

        return false;
    }
};

int main() {


    vector<int> nums = {1,2,3,1};
    int k =3;
    Solution s2;
    cout<<s2.containsNearbyDuplicate(nums,k);
    return 0;
}
