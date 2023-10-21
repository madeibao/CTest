

#include<bits/stdc++.h>
using namespace std;

// 版本一
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp (nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int result = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > result) {
                    result = dp[i][j];
                }
            }
        }
        return result;
    }
};


int main() {

    vector<int> nums1 = {1,2,3,2,1}, nums2 = {3,2,1,4,7};
    Solution s2;
    cout<<s2.findLength(nums1,nums2)<<endl;
    return 0;
}
