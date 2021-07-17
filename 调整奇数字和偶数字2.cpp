

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        //维护两个指针
        int left_point=0,right_point=n-1;
        for(auto num:nums) {
            //如果奇数，将值写入左边并且左指针++
            if(num%2==1) {
                ans[left_point++]=num;
            }
            else {
            //如果偶数，将值写到右边，并且右指针--；
                ans[right_point--]=num;
            }
        }
        return ans;
    }
};


int main(int argc, char** argv) {

	vector<int> nums = {1,2,3,4};
	Solution s;
	vector<int> res;
	res= s.exchange(nums);
	for(int i:res) {
		cout<<i<<endl;
	}

	return 0;
}
