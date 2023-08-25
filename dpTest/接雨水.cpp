

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

    	int n = height.size();

    	vector<int> left(n);
    	vector<int> right(n);

    	left[0] = height[0];
    	right[n-1] = height[n-1];

    	for(int i=1;i<n;i++) {
    		left[i] = max(left[i-1],height[i]);
    		right[n-1-i] = max(right[n-i],height[n-1-i]);
    	}

    	int ans = 0;
    	for(int i=1;i<n;i++) {
    		ans += min(left[i],right[i])-height[i];
    	}

    	return ans;
    }

};

int main() {

    vector<int> nums {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s2;
    cout<<s2.trap(nums)<<endl;
    return 0;
}
