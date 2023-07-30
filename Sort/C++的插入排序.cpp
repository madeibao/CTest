

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void swapExchange(vector<int>& nums) {

        for(int i=1;i<nums.size();i++) {
            int index = i-1;
            int temp = nums[i];
            while(index>=0&&nums[index]>temp) {
                nums[index+1] = nums[index];
                index--;
            }
            nums[index+1] = temp;
        }
    }
};

int main() {

    vector<int> nums {2,3,1,3,9,8,10};
    Solution s2;
    s2.swapExchange(nums);
    for(int i:nums) {
        cout<<i<<" "<<endl;
    }
    return 0;
}

