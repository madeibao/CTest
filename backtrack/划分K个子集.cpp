

// 输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4

// 输出： True
// 说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和


#include<iostream>
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    //i:开始位置， cw:当前值
    bool backtrack(int i, int cw,int k, vector<int> &nums, vector<int> &help, int target){
        if(k == 0)   return true; //目标就是把size元素全装进去
        bool flag = false;
        for(int j = i; j < nums.size(); ++j){
            if(!help[j] && cw + nums[j] <= target){
                help[j] = 1; //做出选择
                if(cw+nums[j] == target)
                    flag = backtrack(0, 0, k-1, nums, help, target); //找到了一组，k=k-1，又回到最初开始循环
                else   
                     flag = backtrack(j+1, cw+nums[j], k, nums, help, target); //没找到
                if(flag) return true;
                help[j] = 0; //撤销选择
            }
        }
        return flag;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        //  用于记录nums中的第i个元素有没有被匹配过
        vector<int> help(n, 0);
        int sum = 0;
        int max = 0;
        for(const auto &c : nums){
            if(max < c) max = c;
            sum += c;
        }

        // 表示，如果不能整除，表示必然不能划分
        if(sum % k != 0 || max > sum/k)    return false;
        int target = sum / k; 
        return backtrack(0, 0, k, nums, help, target);
    }
};


int main() {


	vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
	int k(4);
	Solution s2;
	cout<<s2.canPartitionKSubsets(nums, k)<<endl;
	return 0;
}