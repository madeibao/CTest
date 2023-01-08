
//-----------------------------------------------------------------------------
// C++的全排列

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    int an[10000];
    void back(vector<int>& num,vector<int>& nums){

    	if(num.size()==nums.size()) {
    		ans.push_back(num);
    		return;
    	}

    	for(unsigned int i=0;i<nums.size();i++){
    		if(an[i]) {
    			num.push_back(nums[i]);
    			an[i] = 0;
    			back(num,nums);
    			num.pop_back();
    			an[i] = 1;
    		}
    	}
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>num;
        memset(an,1,sizeof(an));
        back(num,nums);
        return ans;
    }
};

int main(int argc, char** argv) {

	vector<int> nums = {1,2,3};
	vector<vector<int>> res;
	Solution s;
	res = s.permute(nums);

    for(vector<int> a:res) {
        for(int i:a) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

	return 0;
}
