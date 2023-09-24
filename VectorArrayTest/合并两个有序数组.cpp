




#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
            int len1 = nums1.size();
            int len2 = nums2.size();
            nums1.insert(nums1.begin()+m,nums2.begin(),nums2.begin()+n);
            nums1.erase(nums1.begin()+m+n,nums1.end());
            sort(nums1.begin(),nums1.end());
    }
};

int main(int argc, char** argv) {

	vector<int> nums1 = {1,2,3,4};
	vector<int> nums2 = {2,3,6,7};

	Solution s2;
	s2.merge(nums1,nums2);
	

	return 0;
}