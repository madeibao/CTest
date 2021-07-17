
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0 && n == 0) return;
        if (m != 0 && n == 0) return;
        if (m == 0 && n != 0) {
            nums1 = nums2;
            return;
        }

        for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

int main(int argc, char* argv[]) {

	vector<int> nums1 = {1,2,3,0,0,0};
	int m = 3;
	vector<int>nums2 = {2,5,6};
	int n = 3;

	Solution s;
	s.merge(nums1, m, nums2, n);
	for(int i:nums1) {
		cout<<i<<" ";
	}
	return 0;
}
