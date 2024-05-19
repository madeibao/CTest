

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int va = -1, vb = -1, cnta = 0, cntb = 0;

        for(int i=0;i<nums.size();i++ ) {
            if(cnta>0&&nums[i]==va) {
                cnta++;
            }
            else if(cntb>0&&nums[i]==vb) {
                cntb++;
            }
            else if(cnta==0) {
                cnta++;
                va = nums[i];
            }
            else if(cntb==0) {
                cntb++;
                vb = nums[i];
            }
            else {
                cnta--;
                cntb--;
            }
        }   

        cout<<cnta<<" "<<cntb<<" ";

        int cna = 0 ,cnb = 0;

        for(auto& num:nums) {
            if(cnta>0&&num==va) {
                cna++;
            }
            if(cntb>0&&num==vb) {
                cnb++;
            }
        }

        vector<int> ans;

        if(cna>nums.size()/3) {
            ans.push_back(va);
        }

        if(cnb>nums.size()/3) {
            ans.push_back(vb);
        }

        return ans;
    }
};

int main() {

    vector<int> nums = {2,2,2,2,3,3,3,3,1,1};
    vector<int> res;
    Solution s2;
    res = s2.majorityElement(nums);
    for(auto i:res) {
        cout<<i<<" ";
    }

    return 0;
}
