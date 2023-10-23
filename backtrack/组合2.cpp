


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<int> > result;
	int n;

	vector<vector<int>> combine(vector<int>& nums) {

		n = nums.size();
		for(int i=0;i<1<<n;i++) {
            vector<int> path;
            for(int j=0;j<=i;j++) {
                if(i>>j&1) {
                    path.push_back(nums[j]);
                }
            }
            result.push_back(path);
		}

        return result;
    }
};

int main(int argc, char** argv) {

    vector<int> nums = {1,2,3};
    Solution s2;
    vector<vector<int>> res;
    res = s2.combine(nums);
    for(auto i:res) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
	return 0;
}