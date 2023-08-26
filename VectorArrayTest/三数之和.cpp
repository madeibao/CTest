

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // 不能去重

        vector<vector<int>> res;// 最终结果
        int n = nums.size();

        for(int i=0;i<n;i++) {

        	// 如果两个元素相同，直接忽略
        	if(i>0&&nums[i]==nums[i-1]) continue;

        	// 确定第三个元素
        	int c = n-1;

        	// 后面的两个元素之和
        	int target = -nums[i];

        	for(int b=i+1;b<n;b++) {
        		if(b>i+1&&nums[b]==nums[b-1]) continue;

        		// 第二个元素和第三个元素来进行位置比较
        		while(b<c&&nums[b]+nums[c]>target) {
        			c--;
        		}

				if(b==c)break;//若两个指针相等了还无解，就不用再比下去了
				if(nums[b]+nums[c]==target) {
                	res.push_back({nums[i],nums[b],nums[c]});
            	}
        	}
        }

        return res;
    }
};


int main(int argc, char const *argv[])
{
	
	vector<int> nums {-1,0,1,2,-1,-4};
	vector<vector<int>> res;
	Solution s2;
	res = s2.threeSum(nums);
	for(auto i:res) {
		for(auto j:i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}

	return 0;
}