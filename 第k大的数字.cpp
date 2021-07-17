


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        QuickSort(nums, 0, nums.size()-1);
        return nums[nums.size() - k];
    }
    void QuickSort(vector<int> &nums, int left, int right) {
        if (left >= right)
            return;
        int i = left, j = right;
        int base = nums[left]; //base就是基准点，以base为界限，小于base的放到左面，大于的放到右面。
        while (i < j) {
            while (nums[j] >= base && i < j)
                j--;
            while (nums[i] <= base && i < j)
                i++;
            if (i < j)
                swap(nums[i], nums[j]);
        }
        nums[left] = nums[i];
        nums[i] = base;
        QuickSort(nums, left, i - 1);
        QuickSort(nums, i + 1, right);
    }
};


int main(int argc, char* argv[]) {

	vector<int> res {1,2,3,5,6,8,9,10,12,14};
	int k(2);
	Solution s;
	cout<<s.findKthLargest(res, k);
	
	return 0;
}


