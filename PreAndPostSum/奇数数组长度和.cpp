

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {

        int n = arr.size();
        vector<int> preSum(n+1);
        for(int i=0;i<n;i++) {
            preSum[i+1] = preSum[i]+arr[i];
        }

        int sum = 0;
        for(int start = 0;start<n;start++) {
            for(int length=1;start+length<=n;length+=2) {
                int end = start+length-1;
                sum+=preSum[end+1]-preSum[start];
            }
        }

        return sum;
    }

};

int main() {

    vector<int> nums {1,4,2,5,3};
    vector<int> nums2 {10,11,12};
    Solution s2;
    cout<<s2.sumOddLengthSubarrays(nums2)<<endl;
    return 0;
}
