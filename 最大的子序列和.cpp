
#include<iostream>
#include<bits/stdc++.h> 

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int maxSum = nums[0]; //将最大子序和初始值设置为数组第一个数
        int thisSum = 0;    //当前子序和
        for(int i=0;i<len;++i){
            thisSum += nums[i];
            if(thisSum>maxSum){
                maxSum = thisSum; //发现更大的和则更新当前结果
            }
            if(thisSum<0)  {
                thisSum = 0;  //如果当前子序和为负.它一定会使后面的数变得更小,干脆抛弃,置和为0
            }
        }
        return maxSum;
    }
};


int main(int argc, char* argv[]) {

	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	Solution s;
	cout<<s.maxSubArray(nums)<<endl;
	return 0;
}