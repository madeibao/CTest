


/***
    颜色分类，
    将颜色来分类，不用Sort函数
    输入：nums = [2,0,2,1,1,0]
    输出：[0,0,1,1,2,2]

*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=0,k=nums.size()-1;

        while(i<=k) {
            if(nums[i]==0) {
                swap(nums[i++],nums[j++]);
            }
            else if(nums[i]==2) {
                swap(nums[k--],nums[i]);
            }
            else {
                i++;
            }
        }
    }
};


int main(int argc, char* argv[]) {

	vector<int> nums {2,0,2,1,1,0};
	Solution s;
    s.sortColors(nums);
    for(int i:nums) {
        cout<<i<<" "<<endl;
    }
	return 0;
}
