

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        unsigned int i =0,j =0;
        for(i=0;i<nums.size();i++) {
            if(nums[j]!=nums[i]) {
                nums[++j] = nums[i];
            }
        }
        return j+1;
    }
};


int main() {
    Solution s;
    vector<int> res {1,2,2};
    cout<<s.removeDuplicates(res)<<endl;
    return 0;

}
