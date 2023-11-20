







#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> map2;
        vector<int> res;

        stack<int> st;
        for(int n:nums2) {

            while(!st.empty()&&st.top()<n) {
                map2[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }

        while(!st.empty()) {
            map2[st.top()] = -1;
            st.pop();
        }

        for(int n: nums1){
            res.push_back(map2[n]);
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
