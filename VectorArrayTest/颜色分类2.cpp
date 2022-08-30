

#include "iostream"
#include "bits/stdc++.h"

using namespace std; 


class Solution {
public:
void sortColors(vector<int>& nums) {
        int _0 = 0;                 // 定义出现红色次数
        int _1 = 0;                 // 定义出现白色次数
        int _2 = 0;                 // 定义出现蓝色次数
        //统计每个频率出现的次数
		
		for(unsigned int i=0;i<nums.size();i++) {
			if(nums[i]==0) {
				_0+=1;
			}
			if(nums[i]==1) {
				_1+=1;
			}
			if(nums[i]==2) {
				_2+=1;
			}

		}
        nums.clear();   //原来的清空数据
        // 红色赋值
        for(int i = 0; i < _0; i++) {
            nums.push_back(0);
        }
        // 白色赋值
        for(int i = 0; i < _1; i++) {
            nums.push_back(1);
        }
        // 蓝色赋值
        for(int i = 0; i < _2; i++) {
            nums.push_back(2);
        }                
    }
};


int main(int argc, char* argv[]) {

	vector<int> nums {2,0,2,1,1,0;
	Solution s;
	vector<int> res;
	res = s.sortColors(nums);

	for(int i=0;i<res.size();i++) {
		cout<<res[i]<<endl;
	}

	return 0;
}