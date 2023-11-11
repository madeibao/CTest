
#include<iostream>
#include<deque>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int,vector<int>,greater<int>> queue;
        for(int i:nums) {
            queue.push(i);
            if(queue.size()>k) {
                queue.pop();
            }
        }
        return queue.top();
    }
};

int main() {

    vector<int> nums =  {3,2,1,5,6,4};
    int k = 2;
    Solution s;
    cout<<s.findKthLargest(nums,k)<<endl;
    return 0;
}
