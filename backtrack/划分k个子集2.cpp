

#include<iostream>
#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        sort(nums.rbegin(),nums.rend());//从大到小放数字      
        if(sum%k!=0) return false;
        int target=sum/k;//每个桶的容量
        vector<int> buckets(k,target);//k个桶每个桶可以容纳target的数
        return dfs(nums,buckets,k,0);
    }
    bool dfs(vector<int>& nums,vector<int>& buckets,int k,int index){
        if(index>=nums.size()) return true;//如果把数字都分完了
        for(int i=0;i<k;i++){
            if(nums[index]>buckets[i]) continue; //如果当前数字大于桶的容量
            if(i>0&&buckets[i]==buckets[i-1]) continue;
            buckets[i]-=nums[index];
            if(dfs(nums,buckets,k,index+1)) return true;
            buckets[i]+=nums[index]; //不能不回溯，因为有放错桶的可能
        }      
        return false;
    }
};

int main() {


    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k(4);
    Solution s2;
    cout<<s2.canPartitionKSubsets(nums, k)<<endl;
    return 0;
}