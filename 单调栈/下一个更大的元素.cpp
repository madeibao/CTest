


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> map2;
        for(int i=0;i<nums2.size();i++) {
            map2[nums2[i]] = i;
        }

        vector<int> res(nums1.size(),0);
        for(int i=0;i<nums1.size();i++) {

            int curr = nums1[i];

            if(map2.count(curr)) {
                int j = map2[curr]+1;
                while (j < nums2.size() && nums2[j] < curr){
                    ++j;
                }
                res[i] = j < nums2.size() ? nums2[j] : -1;
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};

    Solution s2;
    vector<int> res;
    res = s2.nextGreaterElement(nums1,nums2);
    for(auto i:res) {
        cout<<i<<" ";
    }
    return 0;
}
