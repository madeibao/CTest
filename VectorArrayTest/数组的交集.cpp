


// ----------------------------------------------------------------
// 两个数组的交集

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    	int lena = nums1.size();
    	int lenb = nums2.size();

		sort(nums1.begin(),nums1.end());
		sort(nums2.begin(),nums2.end());
    	int i =0, j=0;

    	vector<int> result;

    	while(i < lena && j<lenb) {
    		if(nums1[i] < nums2[j]) {
    			i++;
    		}
    		else if(nums1[i] > nums2[j]) {
    			j++;
    		}
    		else {
    			result.push_back(nums1[i]);
    			i++;
    			j++;
    		}
    	}
    	return result;
    }

};



int main(int argc, char** argv) {

	vector<int> nums {1,2,2,1};
	vector<int> nums2 = {2,2};
	Solution s2;
	vector<int> result;
	result = s2.intersect(nums, nums2);
	for(int i:result) {
		cout<<i<<" "<<endl;
	}

	return 0;
}