

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	void selectSort(vector<int>& nums) {

		for(unsigned int i=0; i<nums.size()-1;i++) {

			int index = i;
			for(unsigned int j=i+1;j<nums.size();j++) {
				if(nums[j]<nums[index]) {
					index = j;
				}
			}
			
			if(index!=i) {
				swap(nums[i],nums[index]);	
			}

		}
	}
};

int main(int argc, char* argv[]) {
	vector<int> nums {2,2,1,9,10,22,34,20,};
	Solution solution;
	solution.selectSort(nums);
	for(auto& i : nums) {
		cout << i <<" "<<endl;
	}
}