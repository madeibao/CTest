


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> mp;//用来找重复数字
        int mutl=0;
        for(auto &n:nums) {
            mp[n]++;
            if(mp[n]==2)
                mutl=n;
        }

        for(int i=1;i<=nums.size();i++){
            if(mp[i]==0) return {mutl,i};
        }
        return {-1,-1};
    }
};

int main() {
    vector<int> nums {1,2,2,4};
    Solution s2;
    vector<int> res;
    res = s2.findErrorNums(nums);
    for(auto i:res){
        cout<<i<<" ";
    }

    return 0;
}
