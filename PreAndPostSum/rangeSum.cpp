

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        const int N = nums.size();
        preSum.resize(N + 1);
        for (int i = 0; i < N; ++i) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return preSum[j + 1] - preSum[i];
    }
private:
    vector<int> preSum;
};


int main() {


}
