


// 双指针法，两数之和，有序数组。
//  

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size()-1;
        while (start < end) {
            int sum = numbers[start] + numbers[end];
            if (sum > target) {
                --end;
            } else if (sum < target) {
                ++start;
            } else {
                return {start+1, end+1};
            }
        }
        return {};
    }
};



int main(int argc, char* argv[]) {

	vector<int> res = {2,7,8,9};
	int target = 9;

	Solution s;
	vector<int> res2;
	res2 = s.twoSum(res,target);
	for(int i:res2) {
		cout<<i<<" ";
	}
	return 0;
}