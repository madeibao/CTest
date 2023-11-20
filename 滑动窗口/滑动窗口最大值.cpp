

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> queue;

        vector<int> res(nums.size()-k+1);
        int n = nums.size();

        for(int i=0;i<n;i++) {
            if(!queue.empty()&&queue.front()==i-k) {
                queue.pop_front();
            }

            while(!queue.empty()&&nums[queue.back()]<nums[i]) {
                queue.pop_back();
            }

            queue.push_back(i);
            if(i-k+1>=0) {
                res[i-k+1] = nums[queue.front()];
            }
        }
        return res;
    }
};

int main() {

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res;
    Solution s2;
    res = s2.maxSlidingWindow(nums,k);
    for(auto i:res) {
        cout<<i<<endl;
    }

    return 0;
}
