
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

    	int i=0,j=0;
    	for(int i=0;i<nums.size();i++) {
    		if(nums[i]!=0) {
    			nums[j++] = nums[i];
    		}
    	}

    	while(j<nums.size()) {
    		nums[j++] = 0;
    	}
    }
};

int main(int argc, char* argv[]) {

	vector<int> res {0,1,0,3,12};
	Solution s;
	s.moveZeroes(res);

	for(int i=0;i<res.size();i++) {
		cout<<res[i]<<endl;
	}
	return 0;
}



