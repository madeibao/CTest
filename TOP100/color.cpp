


#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
		int i=0,j=0,k= nums.size()-1,m=0;

		while (i<nums.size()) {
			if(nums[i]==2) {
				swap(nums[i++],nums[k--]);
			}
			else if(nums[i]==0) {
				swap(nums[i++],nums[j++]);
			}
			else {
				swap(nums[i],nums[m++]);
			}
		}

    }
};


int main(int argc, char** argv) {

	vector<int> colors {2,0,2,1,1,0};
	Solution solution;
	solution.sortColors(colors);
	for(int i:colors) {
		cout<<i<<" "<<endl;
	}
	return 0;
}