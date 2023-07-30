
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map2;
        for(int i=0;i<nums.size();i++) {
            if(map2.find(target- nums[i])!= map2.end()) {
                int index = map2[target- nums[i]];
                return {i,index};
            }
            map2[nums[i]] = i;
        }
        return {};
    }
};

int main(int argc, char** argv) {

	vector<int> nums = {2,7,11,15};
	int target = 9;
	vector<int> res;
	Solution solution;
	res = solution.twoSum(nums, target);
	for(auto i:res) {
		cout << i << " " <<endl;
	}
	return 0;
}
