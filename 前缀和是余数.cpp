

#include "iostream"
#include "bits/stdc++.h"

using namespace std; //

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m = {{0,-1}};
        int rem = 0;
        for(int i = 0; i < nums.size(); ++i) {
            rem = (rem + nums[i])%k;
            if(m.count(rem)) {
                int pos = m[rem];
                if((i - pos) >= 2)
                    return true;
            }
            else {
                m[rem] = i;
            }
        }
        return false;
    }
};


int main(int argc, char** argv) {

	vector<int> nums {23,2,4,6,7};
	int k(6);

	Solution s; 
	cout<<s.checkSubarraySum(nums, k);
	return 0;
}