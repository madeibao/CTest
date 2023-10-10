

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, sum = 0;
        for (int x: gain) {
            sum += x;
            ans = max(ans, sum);
        }
        return ans;
    }
};



int main( ) {


    vector<int> nums {-5,1,5,0,-7};
    vector<int> nums2 {-4,-3,-2,-1,4,3,2};

    Solution s2;
    cout<<s2.largestAltitude(nums)<<endl;
    return 0;
}



class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        n  = len(gain)
        
        # 1. 计算 n + 1 个点的海拔
        heights = [-inf for _ in range(n + 1)]
        heights[0] = 0
        for i in range(n):
            heights[i + 1] = heights[i] + gain[i]
        
        # 2. 计算最高点的海拔
        res = -inf
        for height in heights:
            if height > res:
                res = height
        
        return res