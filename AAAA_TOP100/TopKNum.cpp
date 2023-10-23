

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> pq;
		for(int i = 0; i < nums.size(); ++i) {
			pq.push(nums[i]);
		}        
		for(int i = 0; i < k-1; ++i) {
			pq.pop();
		}
		return pq.top();
    }
};


class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int sub = len-k;
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i = 0;i<k;i++) {
            pq.push(nums[i]);
        }
        
        for(int i = k;i<len;i++) {
            if(nums[k]>pq.top()) {
                pq.pop();
                pq.push(nums[k]);
            }
        }
        
        return pq.top();
    }
};


int main(int argc, char** argv) {

	vector<int> nums {3,2,1,5,6,4};
	int k(2);
	Solution s;

	cout<<s.findKthLargest(nums,k);
	return 0;
}