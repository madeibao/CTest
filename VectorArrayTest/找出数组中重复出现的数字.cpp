

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {

public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(unsigned int i=0;i<nums.size();i++){
            if(mp.find(nums[i]) != mp.end()) {
                return nums[i];
            }
            else  {
                    mp[nums[i]] ++;
            }
        }
        return -1;
    }
};


int main(int argc, char* argv[])  {
    vector<int> res = {2,2,3,3,4,5,6,7,8};
    Solution s;
    cout<<s.findRepeatNumber(res)<<endl;
    return 0;
}



