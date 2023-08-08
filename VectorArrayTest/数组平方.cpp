
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) { 
    		vector<int> result(nums.size());
            int i=0;
            int j=nums.size()-1;
            while(i<=j){
                if(nums[i]*nums[i]>nums[j]*nums[j]){
                    result[number]=nums[i]*nums[i];
                    number--;
                    i++;
                }else{
                    result[number]=nums[j]*nums[j];
                    number--;
                    j++;
                }
            }
            return result;
        }
};


int main(int argc, char* argv[]) {
	vector<int> nums {-4,-1,0,3,10};
	Solution s2;

	vector<int> result;
	result = s2.sortedSquares(nums);
	for(autot i:result){
		cout<<i<<" ";
	}
	return 0;
}