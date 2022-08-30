



#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = nums.size();
        if (N == 0) return 0;
        int left = 0;
        for (int right = 1; right < N; ++right) {
            if (nums[left] != nums[right]) {
                nums[++left] = nums[right];
            }
        }
        return left + 1;
    }
};


int main(int argc, char* argv[]) {

	vector<int> res {1,1,2};
	Solution s;
	vector<int> res2;
	res2 = s.removeDuplicates(res);
	for(int i=0; i<res2.size();i++) {
		cout <<res2[i] <<endl;
	}

	return 0;
}